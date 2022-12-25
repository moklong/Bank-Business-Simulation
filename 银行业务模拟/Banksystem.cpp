#include<iostream>
#include<string>
#include<Windows.h>

#include "Banksystem.h"
using namespace std;

void startWorking(int open_time, int close_time)
{
	///队链以及窗口的创建
	const int client_array_length = 100;//客户数组最大的长度
	const int window_length = 4;//窗口数量
	Client client[client_array_length];//创建顾客数组
	bubbleSortForClientArray(client, client_array_length);

	LinkedQueue client_queue;//创建队列
	client_queue.joinQueue(client, client_array_length, open_time, close_time);
	//创建四个窗口
	Bank windows[window_length] = { Bank(open_time,close_time),Bank(open_time,close_time),Bank(open_time,close_time),Bank(open_time,close_time) };



	int i;
	int j;

	int index_for_min = 0;//记录结束时间最早的窗口下标
	int bank_end_time = 0;//记录银行结束营业的时间
	int now_temp_all_time_min = 0;//记录当前办理时间最短的那个窗口办理结束的时间

	//将银行结束营业的时间存储并转化为分钟表达
	bank_end_time = windows[0].getBankCloseTime() * 60;

	if (client_queue.empty() == true)
	{
		//如果等待队列一开始为空就退出
	}
	else
	{
		while (client_queue.empty() != true && now_temp_all_time_min <= bank_end_time)
		{
			//如果窗口都不为空
			if (!windows[0].getWindowsEmpty() && !windows[1].getWindowsEmpty() &&
				!windows[2].getWindowsEmpty() && !windows[3].getWindowsEmpty())
			{
				index_for_min = getMinWindow(windows, window_length);//找出办理业务时间最短的窗口

				windows[index_for_min].setWindowsEmpty(true);//时间最小的窗口设置为没人状态
				//将最快办理完业务的窗口的下一个业务开始办理时间设置为上一个业务的结束时间
				windows[index_for_min].setBusinessStartTime(windows[index_for_min].getBusinessEndTime());
				now_temp_all_time_min = windows[index_for_min].getBusinessEndTime();//将此时办理时间最短的窗口的时间设置为总时间

				setWindowsStatusByBankEndTime(windows, window_length, bank_end_time);//找到此时服务时间超过银行营业时间的窗口并将其关闭
			}
			else//否则执行业务
			{
				//执行出队操作
				Client client = client_queue.deleteQueue();

				for (int i = 0; i < window_length; i++)
				{
					if (windows[i].getWindowsEmpty() == true)
					{
						cout << "当前顾客来到在第 " << i + 1 << "窗口办理业务 " << endl;
						client.showClientInfor();//打印当前客户的票的信息
						cout << endl;

						//如果此时到达该窗口的客户的时间远大于窗口上一个业务办理完毕的时间
						//那么将该业务下一个业务的开始时间=下一个顾客到来的时间
						if (client.getClientArriveTime() > windows[i].getBusinessStartTime())
						{
							windows[i].setBusinessStartTime(client.getClientArriveTime());
						}

						windows[i].setWindowsEmpty(false);//将该窗口设置为有人状态 

						switch (client.getBusinessName())//运用当前出队对象的得到办理的业务方法来得到当前出队用户在该窗口办理的业务种类以及逗留时间和当前窗口该业务办理结束时间。 
						{
						case 0:
							//设置当前窗口办理结束时间为，窗口上一个人办理完毕的时间 + 当前到来顾客需要办理的时间 
							windows[i].setBusinessEndTime(windows[i].getBusinessStartTime() + client.getBusinessNameTime());
							//用户逗留时间 = 用户离开的时间（窗口服务当前客户结束时间）- 用户到达的时间
							windows[i].setClientStayBankTime((windows[i].getBusinessEndTime() - client.getClientArriveTime()));//当前窗口顾客逗留时间累加

							windows[i].setSavemoneynum();//当前窗口的存款办理次数+1

							break;

						case 1:
							//设置当前窗口办理结束时间为，窗口上一个人办理完毕的时间 + 当前到来顾客需要办理的时间 
							windows[i].setBusinessEndTime(windows[i].getBusinessStartTime() + client.getBusinessNameTime());
							//用户逗留时间 = 用户离开的时间（窗口服务当前客户结束时间）- 用户到达的时间
							windows[i].setClientStayBankTime((windows[i].getBusinessEndTime() - client.getClientArriveTime()));//当前窗口顾客逗留时间累加

							windows[i].setGetmoneynum();//当前窗口的取款办理次数+1 

							break;

						case 2:
							//设置当前窗口办理结束时间为，窗口上一个人办理完毕的时间 + 当前到来顾客需要办理的时间 
							windows[i].setBusinessEndTime(windows[i].getBusinessStartTime() + client.getBusinessNameTime());
							//用户逗留时间 = 用户离开的时间（窗口服务当前客户结束时间）- 用户到达的时间
							windows[i].setClientStayBankTime((windows[i].getBusinessEndTime() - client.getClientArriveTime()));//当前窗口顾客逗留时间累加

							windows[i].setReportLossofnum();//当前窗口的挂失办理次数+1 
							break;

						case 3:
							//设置当前窗口办理结束时间为，窗口上一个人办理完毕的时间 + 当前到来顾客需要办理的时间 
							windows[i].setBusinessEndTime(windows[i].getBusinessStartTime() + client.getBusinessNameTime());
							//用户逗留时间 = 用户离开的时间（窗口服务当前客户结束时间）- 用户到达的时间
							windows[i].setClientStayBankTime((windows[i].getBusinessEndTime() - client.getClientArriveTime()));//当前窗口顾客逗留时间累加

							windows[i].setRefundnum();//当前窗口的贷款办理次数+1 
							break;

						default:
							cout << "error！" << endl;
							break;
						}
					}
				}
			}
			Sleep(500);
		}
		cout << "今日数据生成已完成 :" << endl;
		statisticData(windows, window_length);
		startAnotherSimulate();
	}
}

void bubbleSortForClientArray(Client *client, int client_length)
{
	int exchange;//交换位置记录
	Client temp_client;//临时存储
	int bound;

	exchange = client_length - 1;
	while (exchange != 0)
	{
		bound = exchange;
		exchange = 0;

		for (int j = 0; j < bound; j++)
		{
			if (client[j].getClientArriveTime() > client[j + 1].getClientArriveTime())
			{
				temp_client = client[j];
				client[j] = client[j + 1];
				client[j + 1] = temp_client;
			}
			exchange = j;
		}
	}
}

void startAnotherSimulate()
{
	int select = 0;

	cout << "是否准备离开获取其他的数据？如果准备离开，请输入“1”" << endl;

	while (select != 1)
	{
		cin >> select;
		if (select != 1)
		{
			cout << "输入错误，请重新输入！" << endl;
		}
	}
}

void showAllwindows(Bank* window, int window_length)
{
	int count = 0;
	for (int i = 0; i < window_length; i++)
	{
		cout << "窗口" << ++count <<
			" 的存款办理次数：" << window[i].getSavemoneynum() << "    " <<
			"取款办理次数：" << window[i].getGetmoneynum() << "    " <<
			"挂失办理次数" << window[i].getReportLossofnum() << "    " <<
			"贷款办理次数" << window[i].getRefundnum() << endl;
		cout << "该窗口总计接纳人数：" << (window[i].getSavemoneynum() + window[i].getGetmoneynum() + window[i].getReportLossofnum() + window[i].getRefundnum());
		cout << endl;
	}
}

void statisticData(Bank* window, int window_length)
{
	int client_all_stay_time = 0;
	int all_client_num = 0;//今日总的到客量
	double client_average_time;//客户今天平均逗留的时间

	for (int i = 0; i < window_length; i++)
	{
		client_all_stay_time += window[i].getClientStayBankTime();
		//总的客户量，所有窗口所有业务相加
		all_client_num+= (window[i].getSavemoneynum() + window[i].getGetmoneynum() + window[i].getReportLossofnum() + window[i].getRefundnum());
	}
	//输出窗口的信息
	showAllwindows(window, window_length);
	//客户一天平均的逗留时间
	client_average_time = ((double)client_all_stay_time / (double)all_client_num);
	cout << "客户今日平均逗留时间为：" << client_average_time << endl;
}

void setWindowsStatusByBankEndTime(Bank* window, int window_length, int close_time)
{
	for (int i = 0; i < window_length; i++)
	{
		if (window[i].getBusinessStartTime() >= close_time)
		{
			window[i].setWindowsEmpty(false);
		}
	}
}

int getMinWindow(Bank* window, int window_length)
{
	int index = 0;
	int min = window[0].getBusinessEndTime();

	for (int i = 0; i < window_length; i++)
	{
		if (min >= window[i].getBusinessEndTime())
		{
			min = window[i].getBusinessEndTime();
			index = i;//记录结束时间最小的窗口下标
		}
	}
	return index;
}

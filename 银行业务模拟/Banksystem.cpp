#include<iostream>
#include<string>
#include<Windows.h>

#include "Banksystem.h"
using namespace std;

void startWorking(int open_time, int close_time)
{
	///�����Լ����ڵĴ���
	const int client_array_length = 100;//�ͻ��������ĳ���
	const int window_length = 4;//��������
	Client client[client_array_length];//�����˿�����
	bubbleSortForClientArray(client, client_array_length);

	LinkedQueue client_queue;//��������
	client_queue.joinQueue(client, client_array_length, open_time, close_time);
	//�����ĸ�����
	Bank windows[window_length] = { Bank(open_time,close_time),Bank(open_time,close_time),Bank(open_time,close_time),Bank(open_time,close_time) };



	int i;
	int j;

	int index_for_min = 0;//��¼����ʱ������Ĵ����±�
	int bank_end_time = 0;//��¼���н���Ӫҵ��ʱ��
	int now_temp_all_time_min = 0;//��¼��ǰ����ʱ����̵��Ǹ����ڰ��������ʱ��

	//�����н���Ӫҵ��ʱ��洢��ת��Ϊ���ӱ��
	bank_end_time = windows[0].getBankCloseTime() * 60;

	if (client_queue.empty() == true)
	{
		//����ȴ�����һ��ʼΪ�վ��˳�
	}
	else
	{
		while (client_queue.empty() != true && now_temp_all_time_min <= bank_end_time)
		{
			//������ڶ���Ϊ��
			if (!windows[0].getWindowsEmpty() && !windows[1].getWindowsEmpty() &&
				!windows[2].getWindowsEmpty() && !windows[3].getWindowsEmpty())
			{
				index_for_min = getMinWindow(windows, window_length);//�ҳ�����ҵ��ʱ����̵Ĵ���

				windows[index_for_min].setWindowsEmpty(true);//ʱ����С�Ĵ�������Ϊû��״̬
				//����������ҵ��Ĵ��ڵ���һ��ҵ��ʼ����ʱ������Ϊ��һ��ҵ��Ľ���ʱ��
				windows[index_for_min].setBusinessStartTime(windows[index_for_min].getBusinessEndTime());
				now_temp_all_time_min = windows[index_for_min].getBusinessEndTime();//����ʱ����ʱ����̵Ĵ��ڵ�ʱ������Ϊ��ʱ��

				setWindowsStatusByBankEndTime(windows, window_length, bank_end_time);//�ҵ���ʱ����ʱ�䳬������Ӫҵʱ��Ĵ��ڲ�����ر�
			}
			else//����ִ��ҵ��
			{
				//ִ�г��Ӳ���
				Client client = client_queue.deleteQueue();

				for (int i = 0; i < window_length; i++)
				{
					if (windows[i].getWindowsEmpty() == true)
					{
						cout << "��ǰ�˿������ڵ� " << i + 1 << "���ڰ���ҵ�� " << endl;
						client.showClientInfor();//��ӡ��ǰ�ͻ���Ʊ����Ϣ
						cout << endl;

						//�����ʱ����ô��ڵĿͻ���ʱ��Զ���ڴ�����һ��ҵ�������ϵ�ʱ��
						//��ô����ҵ����һ��ҵ��Ŀ�ʼʱ��=��һ���˿͵�����ʱ��
						if (client.getClientArriveTime() > windows[i].getBusinessStartTime())
						{
							windows[i].setBusinessStartTime(client.getClientArriveTime());
						}

						windows[i].setWindowsEmpty(false);//���ô�������Ϊ����״̬ 

						switch (client.getBusinessName())//���õ�ǰ���Ӷ���ĵõ������ҵ�񷽷����õ���ǰ�����û��ڸô��ڰ����ҵ�������Լ�����ʱ��͵�ǰ���ڸ�ҵ��������ʱ�䡣 
						{
						case 0:
							//���õ�ǰ���ڰ������ʱ��Ϊ��������һ���˰�����ϵ�ʱ�� + ��ǰ�����˿���Ҫ�����ʱ�� 
							windows[i].setBusinessEndTime(windows[i].getBusinessStartTime() + client.getBusinessNameTime());
							//�û�����ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
							windows[i].setClientStayBankTime((windows[i].getBusinessEndTime() - client.getClientArriveTime()));//��ǰ���ڹ˿Ͷ���ʱ���ۼ�

							windows[i].setSavemoneynum();//��ǰ���ڵĴ��������+1

							break;

						case 1:
							//���õ�ǰ���ڰ������ʱ��Ϊ��������һ���˰�����ϵ�ʱ�� + ��ǰ�����˿���Ҫ�����ʱ�� 
							windows[i].setBusinessEndTime(windows[i].getBusinessStartTime() + client.getBusinessNameTime());
							//�û�����ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
							windows[i].setClientStayBankTime((windows[i].getBusinessEndTime() - client.getClientArriveTime()));//��ǰ���ڹ˿Ͷ���ʱ���ۼ�

							windows[i].setGetmoneynum();//��ǰ���ڵ�ȡ��������+1 

							break;

						case 2:
							//���õ�ǰ���ڰ������ʱ��Ϊ��������һ���˰�����ϵ�ʱ�� + ��ǰ�����˿���Ҫ�����ʱ�� 
							windows[i].setBusinessEndTime(windows[i].getBusinessStartTime() + client.getBusinessNameTime());
							//�û�����ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
							windows[i].setClientStayBankTime((windows[i].getBusinessEndTime() - client.getClientArriveTime()));//��ǰ���ڹ˿Ͷ���ʱ���ۼ�

							windows[i].setReportLossofnum();//��ǰ���ڵĹ�ʧ�������+1 
							break;

						case 3:
							//���õ�ǰ���ڰ������ʱ��Ϊ��������һ���˰�����ϵ�ʱ�� + ��ǰ�����˿���Ҫ�����ʱ�� 
							windows[i].setBusinessEndTime(windows[i].getBusinessStartTime() + client.getBusinessNameTime());
							//�û�����ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
							windows[i].setClientStayBankTime((windows[i].getBusinessEndTime() - client.getClientArriveTime()));//��ǰ���ڹ˿Ͷ���ʱ���ۼ�

							windows[i].setRefundnum();//��ǰ���ڵĴ���������+1 
							break;

						default:
							cout << "error��" << endl;
							break;
						}
					}
				}
			}
			Sleep(500);
		}
		cout << "����������������� :" << endl;
		statisticData(windows, window_length);
		startAnotherSimulate();
	}
}

void bubbleSortForClientArray(Client *client, int client_length)
{
	int exchange;//����λ�ü�¼
	Client temp_client;//��ʱ�洢
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

	cout << "�Ƿ�׼���뿪��ȡ���������ݣ����׼���뿪�������롰1��" << endl;

	while (select != 1)
	{
		cin >> select;
		if (select != 1)
		{
			cout << "����������������룡" << endl;
		}
	}
}

void showAllwindows(Bank* window, int window_length)
{
	int count = 0;
	for (int i = 0; i < window_length; i++)
	{
		cout << "����" << ++count <<
			" �Ĵ����������" << window[i].getSavemoneynum() << "    " <<
			"ȡ����������" << window[i].getGetmoneynum() << "    " <<
			"��ʧ�������" << window[i].getReportLossofnum() << "    " <<
			"����������" << window[i].getRefundnum() << endl;
		cout << "�ô����ܼƽ���������" << (window[i].getSavemoneynum() + window[i].getGetmoneynum() + window[i].getReportLossofnum() + window[i].getRefundnum());
		cout << endl;
	}
}

void statisticData(Bank* window, int window_length)
{
	int client_all_stay_time = 0;
	int all_client_num = 0;//�����ܵĵ�����
	double client_average_time;//�ͻ�����ƽ��������ʱ��

	for (int i = 0; i < window_length; i++)
	{
		client_all_stay_time += window[i].getClientStayBankTime();
		//�ܵĿͻ��������д�������ҵ�����
		all_client_num+= (window[i].getSavemoneynum() + window[i].getGetmoneynum() + window[i].getReportLossofnum() + window[i].getRefundnum());
	}
	//������ڵ���Ϣ
	showAllwindows(window, window_length);
	//�ͻ�һ��ƽ���Ķ���ʱ��
	client_average_time = ((double)client_all_stay_time / (double)all_client_num);
	cout << "�ͻ�����ƽ������ʱ��Ϊ��" << client_average_time << endl;
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
			index = i;//��¼����ʱ����С�Ĵ����±�
		}
	}
	return index;
}

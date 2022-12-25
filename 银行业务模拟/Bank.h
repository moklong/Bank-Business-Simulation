#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class Bank
{
public:
	Bank();
	~Bank();

	Bank(int open_time, int close_time);
	//获取各个属性的函数
	int getBankAllTime();//获取银行总的营业时间
	bool getWindowsEmpty();//当前窗口是否为空
	int getClientStayBankTime();//客户在此窗口逗留的总时间
	int getSavemoneynum();//获取存款业务办理次数
	int getGetmoneynum();//获取取款业务办理次数
	int getReportLossofnum();//获取挂失业务办理次数
	int getRefundnum();//获取还款业务办理次数
	int getBankOpenTime();//获取银行开始运营时间
	int getBankCloseTime();//获取银行结束营运时间
	int getBusinessStartTime();//获取开始办理业务时间
	int getBusinessEndTime();//获取上一个业务办理结束的时间

	//各个属性的set方法
	void setBankAllTime(int time);//设置银行总的营业时间
	void setWindowsEmpty(bool status);//设置当前窗口是否为空常用
	void setClientStayBankTime(int time);//客户在此窗口逗留的总时间
	void setSavemoneynum();//设置存款业务办理次数
	void setGetmoneynum();//设置取款业务办理次数
	void setReportLossofnum();//设置挂失业务办理次数
	void setRefundnum();//设置还款业务办理次数
	void setBankOpenTime(int time);//设置银行开始运营时间
	void setBankCloseTime(int time);//设置银行结束营运时间
	void setBusinessStartTime(int time);//设置开始办理业务时间
	void setBusinessEndTime(int time);//获取上一个业务办理结束的时间

private:
	int bank_open_time;//银行开始营业时间
	int bank_close_time;//银行结束营业时间
	int bank_all_time;//银行总的营业时间

	int business_start_time;//开始办理业务的时间
	int business_end_time;//上一个业务办理的结束时间

	int save_money_num;//存款业务办理次数
	int get_money_num;//取款业务办理时间
	int report_loss_of_num;//挂失业务办理次数
	int refund_num;//还款业务办理次数

	int client_stay_bank_time;//顾客在银行逗留时间
	bool windows_empty;//窗口是否为空
};


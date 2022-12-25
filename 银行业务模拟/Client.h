#pragma once
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

class Client
{
public:

	Client();
	~Client();

	void randomClient();//构造函数调用随机创建顾客
	void showClientInfor();//打印顾客信息

	//各个属性的获取
	int getClientID();
	int getClientArriveTime();;
	int getClientArriveTimeHour();
	int getClientArriveTimeMinutes();
	int getBusinessName();
	int getBusinessNameTime();

	//各个属性的set方法
	void setClientID(int _a);
	void setClientArriveTime(int _a);;
	void setClientArriveTimeHour(int _a);
	void setClientArriveTimeMinutes(int _a);
	void setBusinessName(int _a);
	void setBusinessNameTime(int _a);


private:
	int client_ID;//顾客编号（无序随机） 
	int client_arrive_time_hour;//顾客到达银行的时间（小时） 
	int client_arrive_time_minutes;//顾客到达银行的时间（分钟） 
	int client_arrive_time;//顾客到达银行的总时间（分钟） 
	int business_name;//业务种类
	int business_name_time;//业务办理的需要时间 
};


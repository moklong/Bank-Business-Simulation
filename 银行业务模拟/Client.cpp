#include "Client.h"

Client::Client()
{
	randomClient();
}

Client::~Client()
{
}

//构造函数调用随机创建客户
void Client::randomClient()
{
	this->client_ID = rand() % 10000;//初始化得到一位四位数的客户编号

	this->business_name = rand() % 4;//客户办理的业务编号位0-3
	switch (this->business_name)
	{
	case 0:
		this->business_name_time = 10;//设置此时顾客办理业务的时间
		break;
	case 1:
		this->business_name_time = 25;
		break;
	case 2:
		this->business_name_time = 40;
		break;
	case 4:
		this->business_name_time = 60;
		break;
	default:
		break;
	}

	this->client_arrive_time_hour = rand() % 24;//顾客到达银行的时间
	this->client_arrive_time_minutes = 1 + rand() % 59;//顾客到达的时间（分钟）

	//初始化总时间
	this->client_arrive_time = ((this->client_arrive_time_hour * 60) + client_arrive_time_minutes);
}

void Client::showClientInfor()
{
	cout << "----------------------------------------------------------------" << endl;
	cout << " 顾客到来，当前到来的顾客信息为：" << endl;
	cout << "客户ID:" << this->client_ID << " " << "客户到达时间：" << this->client_arrive_time_hour << "时" << this->client_arrive_time_minutes << "分" << endl;

	string client_business_name;//不是client类的属性，临时定义的

	switch (this->business_name)
	{
	case 0:
		client_business_name = "存款";//设置此时该顾客办理的业务
		break;

	case 1:
		client_business_name = "取款";
		break;

	case 2:
		client_business_name = "挂失";
		break;

	case 3:
		client_business_name = "还贷";
		break;

	default:
		break;
	}

	cout << "该客户办理的业务为：" << client_business_name << endl;
	cout << "----------------------------------------------------------------" << endl;

}


//各个属性的获取
int Client::getClientID()
{
	return this->client_ID;
}

int Client::getClientArriveTime()
{
	return this->client_arrive_time;
}

int Client::getClientArriveTimeHour()
{
	return this->client_arrive_time_hour;
}

int Client::getClientArriveTimeMinutes()
{
	return this->client_arrive_time_minutes;
}

int Client::getBusinessName()
{
	return this -> business_name;
}

int Client::getBusinessNameTime()
{
	return this->business_name_time;
}


//各个属性的设置
void Client::setClientID(int _a)
{
	this->client_ID = _a;
}

void Client::setClientArriveTime(int _a)
{
	this->client_arrive_time = _a;
}

void Client::setClientArriveTimeHour(int _a)
{
	this->client_arrive_time_hour = _a;
}

void Client::setClientArriveTimeMinutes(int _a)
{
	this->client_arrive_time_minutes = _a;
}

void Client::setBusinessName(int _a)
{
	this->business_name = _a;
}

void Client::setBusinessNameTime(int _a)
{
	this->business_name_time = _a;
}

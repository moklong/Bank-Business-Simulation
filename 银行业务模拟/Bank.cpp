#include "Bank.h"


Bank::~Bank()
{
}

Bank::Bank(int open_time, int close_time)
{
	this->bank_open_time = open_time;
	this->bank_close_time = close_time;
	this->bank_all_time = this->bank_close_time * 60 - this->bank_open_time * 60; //设置银行结束营业时间（分钟） 

	this->business_start_time = bank_open_time * 60;//开始办理业务时间此时初始化为银行开门时间（分钟） 
	this->business_end_time = bank_open_time * 60;//上一个业务办理的结束时间初始化，由于此时还没处理业务，所以初始化为开门时间（分钟） 

	this->save_money_num = 0;//存款业务办理次数
	this->get_money_num = 0;//取款业务办理次数 
	this->report_loss_of_num = 0;//挂失业务办理次数 
	this->refund_num = 0;//还款业务办理所次数

	this->windows_empty = false;//初始化窗口为不空也就是未开门的状态 

	//用户逗留时间 = 用户离开的时间（窗口服务当前客户结束时间）- 用户到达的时间
	this->client_stay_bank_time = 0;
}

int Bank::getBankAllTime()
{
	return this->bank_all_time;
}

bool Bank::getWindowsEmpty()
{
	return this->windows_empty;
}

int Bank::getClientStayBankTime()
{
	return this->client_stay_bank_time;
}

int Bank::getSavemoneynum()
{
	return this->save_money_num;
}

int Bank::getGetmoneynum()
{
	return this->get_money_num;
}

int Bank::getReportLossofnum()
{
	return report_loss_of_num;
}

int Bank::getRefundnum()
{
	return refund_num;
}

int Bank::getBankOpenTime()
{
	return bank_open_time;
}

int Bank::getBankCloseTime()
{
	return bank_close_time;
}

int Bank::getBusinessStartTime()
{
	return business_start_time;
}

int Bank::getBusinessEndTime()
{
	return business_end_time;
}

void Bank::setBankAllTime(int time)
{
	this->bank_all_time = time;
}

void Bank::setWindowsEmpty(bool status)
{
	this->windows_empty = status;
}

void Bank::setClientStayBankTime(int time)
{
	this->client_stay_bank_time += time;
}

void Bank::setSavemoneynum()
{
	this->save_money_num += 1;
}

void Bank::setGetmoneynum()
{
	this->get_money_num += 1;
}

void Bank::setReportLossofnum()
{
	this->report_loss_of_num += 1;
}

void Bank::setRefundnum()
{
	this->refund_num += 1;
}

void Bank::setBankOpenTime(int time)
{
	this->bank_open_time = time;
}

void Bank::setBankCloseTime(int time)
{
	this->bank_close_time = time;
}

void Bank::setBusinessStartTime(int time)
{
	this->business_start_time = time;
}

void Bank::setBusinessEndTime(int time)
{
	this->business_end_time = time;
}

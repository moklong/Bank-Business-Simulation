#include "Bank.h"


Bank::~Bank()
{
}

Bank::Bank(int open_time, int close_time)
{
	this->bank_open_time = open_time;
	this->bank_close_time = close_time;
	this->bank_all_time = this->bank_close_time * 60 - this->bank_open_time * 60; //�������н���Ӫҵʱ�䣨���ӣ� 

	this->business_start_time = bank_open_time * 60;//��ʼ����ҵ��ʱ���ʱ��ʼ��Ϊ���п���ʱ�䣨���ӣ� 
	this->business_end_time = bank_open_time * 60;//��һ��ҵ�����Ľ���ʱ���ʼ�������ڴ�ʱ��û����ҵ�����Գ�ʼ��Ϊ����ʱ�䣨���ӣ� 

	this->save_money_num = 0;//���ҵ��������
	this->get_money_num = 0;//ȡ��ҵ�������� 
	this->report_loss_of_num = 0;//��ʧҵ�������� 
	this->refund_num = 0;//����ҵ�����������

	this->windows_empty = false;//��ʼ������Ϊ����Ҳ����δ���ŵ�״̬ 

	//�û�����ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
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

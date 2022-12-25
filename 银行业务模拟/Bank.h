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
	//��ȡ�������Եĺ���
	int getBankAllTime();//��ȡ�����ܵ�Ӫҵʱ��
	bool getWindowsEmpty();//��ǰ�����Ƿ�Ϊ��
	int getClientStayBankTime();//�ͻ��ڴ˴��ڶ�������ʱ��
	int getSavemoneynum();//��ȡ���ҵ��������
	int getGetmoneynum();//��ȡȡ��ҵ��������
	int getReportLossofnum();//��ȡ��ʧҵ��������
	int getRefundnum();//��ȡ����ҵ��������
	int getBankOpenTime();//��ȡ���п�ʼ��Ӫʱ��
	int getBankCloseTime();//��ȡ���н���Ӫ��ʱ��
	int getBusinessStartTime();//��ȡ��ʼ����ҵ��ʱ��
	int getBusinessEndTime();//��ȡ��һ��ҵ����������ʱ��

	//�������Ե�set����
	void setBankAllTime(int time);//���������ܵ�Ӫҵʱ��
	void setWindowsEmpty(bool status);//���õ�ǰ�����Ƿ�Ϊ�ճ���
	void setClientStayBankTime(int time);//�ͻ��ڴ˴��ڶ�������ʱ��
	void setSavemoneynum();//���ô��ҵ��������
	void setGetmoneynum();//����ȡ��ҵ��������
	void setReportLossofnum();//���ù�ʧҵ��������
	void setRefundnum();//���û���ҵ��������
	void setBankOpenTime(int time);//�������п�ʼ��Ӫʱ��
	void setBankCloseTime(int time);//�������н���Ӫ��ʱ��
	void setBusinessStartTime(int time);//���ÿ�ʼ����ҵ��ʱ��
	void setBusinessEndTime(int time);//��ȡ��һ��ҵ����������ʱ��

private:
	int bank_open_time;//���п�ʼӪҵʱ��
	int bank_close_time;//���н���Ӫҵʱ��
	int bank_all_time;//�����ܵ�Ӫҵʱ��

	int business_start_time;//��ʼ����ҵ���ʱ��
	int business_end_time;//��һ��ҵ�����Ľ���ʱ��

	int save_money_num;//���ҵ��������
	int get_money_num;//ȡ��ҵ�����ʱ��
	int report_loss_of_num;//��ʧҵ��������
	int refund_num;//����ҵ��������

	int client_stay_bank_time;//�˿������ж���ʱ��
	bool windows_empty;//�����Ƿ�Ϊ��
};


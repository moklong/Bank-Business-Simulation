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

	void randomClient();//���캯��������������˿�
	void showClientInfor();//��ӡ�˿���Ϣ

	//�������ԵĻ�ȡ
	int getClientID();
	int getClientArriveTime();;
	int getClientArriveTimeHour();
	int getClientArriveTimeMinutes();
	int getBusinessName();
	int getBusinessNameTime();

	//�������Ե�set����
	void setClientID(int _a);
	void setClientArriveTime(int _a);;
	void setClientArriveTimeHour(int _a);
	void setClientArriveTimeMinutes(int _a);
	void setBusinessName(int _a);
	void setBusinessNameTime(int _a);


private:
	int client_ID;//�˿ͱ�ţ���������� 
	int client_arrive_time_hour;//�˿͵������е�ʱ�䣨Сʱ�� 
	int client_arrive_time_minutes;//�˿͵������е�ʱ�䣨���ӣ� 
	int client_arrive_time;//�˿͵������е���ʱ�䣨���ӣ� 
	int business_name;//ҵ������
	int business_name_time;//ҵ��������Ҫʱ�� 
};


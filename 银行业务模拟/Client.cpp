#include "Client.h"

Client::Client()
{
	randomClient();
}

Client::~Client()
{
}

//���캯��������������ͻ�
void Client::randomClient()
{
	this->client_ID = rand() % 10000;//��ʼ���õ�һλ��λ���Ŀͻ����

	this->business_name = rand() % 4;//�ͻ������ҵ����λ0-3
	switch (this->business_name)
	{
	case 0:
		this->business_name_time = 10;//���ô�ʱ�˿Ͱ���ҵ���ʱ��
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

	this->client_arrive_time_hour = rand() % 24;//�˿͵������е�ʱ��
	this->client_arrive_time_minutes = 1 + rand() % 59;//�˿͵����ʱ�䣨���ӣ�

	//��ʼ����ʱ��
	this->client_arrive_time = ((this->client_arrive_time_hour * 60) + client_arrive_time_minutes);
}

void Client::showClientInfor()
{
	cout << "----------------------------------------------------------------" << endl;
	cout << " �˿͵�������ǰ�����Ĺ˿���ϢΪ��" << endl;
	cout << "�ͻ�ID:" << this->client_ID << " " << "�ͻ�����ʱ�䣺" << this->client_arrive_time_hour << "ʱ" << this->client_arrive_time_minutes << "��" << endl;

	string client_business_name;//����client������ԣ���ʱ�����

	switch (this->business_name)
	{
	case 0:
		client_business_name = "���";//���ô�ʱ�ù˿Ͱ����ҵ��
		break;

	case 1:
		client_business_name = "ȡ��";
		break;

	case 2:
		client_business_name = "��ʧ";
		break;

	case 3:
		client_business_name = "����";
		break;

	default:
		break;
	}

	cout << "�ÿͻ������ҵ��Ϊ��" << client_business_name << endl;
	cout << "----------------------------------------------------------------" << endl;

}


//�������ԵĻ�ȡ
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


//�������Ե�����
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

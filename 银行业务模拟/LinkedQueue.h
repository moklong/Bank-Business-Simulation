#pragma once
#include"Client.h"

struct Person
{
	Client client;//�ͻ���Ķ���
	Person* next;//ָ����
};

class LinkedQueue
{
public:
	LinkedQueue();
	~LinkedQueue();

	//��Ӳ�������Ҫ�Ĳ�����client������飬���鳤�ȣ�bank��Ķ��󣬸������п��ź͹��ŵ�ʱ��
	void joinQueue(Client* client, int client_length, int open_time, int close_time);
	Client deleteQueue();//���Ӳ���
	bool empty();//�ж϶����Ƿ�Ϊ��
	int getQueueLength();//��ȡ�����ĳ���

private:
	Person* front;//��ͷָ��
	Person* rear;//��βָ��
	int length;//��������
};


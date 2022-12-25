#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
	Person* p = new Person;//�½�һ���ڵ�
	p->next = NULL;

	front = p;
	rear = p;

	this->length = 0;
}

LinkedQueue::~LinkedQueue()
{
	Person* p = front;

	while (p != NULL)
	{
		p = p->next;
		delete front;
		front = p;
	}
	front = NULL;
	rear = NULL;
}

void LinkedQueue::joinQueue(Client* client, int client_length, int open_time, int close_time)
{
	int i = 0;//����ѭ�� 

	//ѭ�����
	//ע�⣺���д��ڵ�Ӫҵ��ʼʱ��ͽ���ʱ����Сʱ���������ж�תΪ����

	for (i = 0; i < client_length; i++)
	{
		//�˿��ܷ�����Ǻ����д��ڵ�Ӫҵ��ʼʱ��ͽ���ʱ���й�
		if ((client[i].getClientArriveTime() >= (open_time * 60)) && (client[i].getClientArriveTime() < (close_time * 60)))
		{
			Person* p = new Person;//�½�һ������ָ��

			p->client = client[i];//��ʼ�������� 
			p->next = NULL; //��ʼ��ָ����

			//β�� 
			rear->next = p;
			rear = p;

			length++;
		}
	}
}

Client LinkedQueue::deleteQueue()
{
	Person* p = NULL;
	Client client;

	if (rear == front)
	{
		throw"�ӿ�";
	}
	p = front->next;
	client = p->client;//�洢���Ӷ���
	front->next = p->next;

	if (p->next == NULL)
	{
		rear = front;
	}
	delete p;


	return client;
}

bool LinkedQueue::empty()
{
	bool result = false;

	if (front == rear)
	{
		result = true;
	}
	return result;
	return false;
}

int LinkedQueue::getQueueLength()
{
	return this->length;
}

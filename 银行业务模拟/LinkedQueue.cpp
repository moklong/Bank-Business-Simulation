#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
	Person* p = new Person;//新建一个节点
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
	int i = 0;//控制循环 

	//循环入队
	//注意：银行窗口的营业开始时间和结束时间是小时，在这里判断转为分钟

	for (i = 0; i < client_length; i++)
	{
		//顾客能否入队是和银行窗口的营业开始时间和结束时间有关
		if ((client[i].getClientArriveTime() >= (open_time * 60)) && (client[i].getClientArriveTime() < (close_time * 60)))
		{
			Person* p = new Person;//新建一个工作指针

			p->client = client[i];//初始化数据域 
			p->next = NULL; //初始化指针域

			//尾插 
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
		throw"队空";
	}
	p = front->next;
	client = p->client;//存储出队对象
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

#pragma once
#include"Client.h"

struct Person
{
	Client client;//客户类的对象
	Person* next;//指针域
};

class LinkedQueue
{
public:
	LinkedQueue();
	~LinkedQueue();

	//入队操作，需要的参数：client类的数组，数组长度，bank类的对象，告诉银行开门和关门的时间
	void joinQueue(Client* client, int client_length, int open_time, int close_time);
	Client deleteQueue();//出队操作
	bool empty();//判断队列是否为空
	int getQueueLength();//获取队链的长度

private:
	Person* front;//队头指针
	Person* rear;//队尾指针
	int length;//队链长度
};


#pragma once
#include"Client.h"
#include"Bank.h"
#include"LinkedQueue.h"
#include<iostream>
using namespace std;

//���ڿ�ʼ����
void startWorking(int open_time, int close_time);


//��Ҫ�Ĺ��ܺ���
//ð���������ǰ�Ĳ�����
void bubbleSortForClientArray(Client *client, int client_length);

//�Ƿ�׼����һ��ģ��
void startAnotherSimulate();

//��ӡ���д��ڵ�ÿ��ҵ�����Ĵ���
void showAllwindows(Bank* window, int window_length);

//ͳ��һ��ͻ������е�ƽ������ʱ��
void statisticData(Bank* window, int window_length);

//�ҵ���ǰ����ʱ�䳬��������Ӫҵʱ��Ĵ��ڣ�������ر�
void setWindowsStatusByBankEndTime(Bank* window, int window_length, int close_time);

//�ҵ�ҵ�����ʱ����С�Ĵ���
int getMinWindow(Bank* window, int window_length);
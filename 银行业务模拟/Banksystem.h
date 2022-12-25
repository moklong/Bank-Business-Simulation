#pragma once
#include"Client.h"
#include"Bank.h"
#include"LinkedQueue.h"
#include<iostream>
using namespace std;

//窗口开始工作
void startWorking(int open_time, int close_time);


//主要的功能函数
//冒泡排序（入队前的操作）
void bubbleSortForClientArray(Client *client, int client_length);

//是否准备下一轮模拟
void startAnotherSimulate();

//打印所有窗口的每个业务办理的次数
void showAllwindows(Bank* window, int window_length);

//统计一天客户在银行的平均逗留时间
void statisticData(Bank* window, int window_length);

//找到当前服务时间超过了银行营业时间的窗口，并将其关闭
void setWindowsStatusByBankEndTime(Bank* window, int window_length, int close_time);

//找到业务办理时间最小的窗口
int getMinWindow(Bank* window, int window_length);
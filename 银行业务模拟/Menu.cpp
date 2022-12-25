#include"Menu.h"
#include"Bank.h"
#include"Banksystem.h"
#include"Client.h"
#include"LinkedQueue.h"

//初始界面
void welcome()
{
	system("color f9");

	cout << "                    ***---------------------------------------------------------------------***" << endl;
	cout << "                                                                                               " << endl;
	cout << "						欢迎来到					" << endl;

	Sleep(1500);//沉睡1.5秒

	cout << "						我的银行					" << endl;
	cout << "                                                                                               " << endl;
	cout << "                    ***---------------------------------------------------------------------***" << endl;

	Sleep(1500);//沉睡1.5秒

	cout << "                    ===========================================================================" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                       如果你固定了时间                                  *" << endl;
	cout << "                    *                       时间将无法被改变                                  *" << endl;

	cout << "                    *                       如果你想改变使时间，你可以退出                    *" << endl;
	cout << "                    *                       程序将重新启动   	  		              *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    ===========================================================================" << endl;

	Sleep(1000);//1秒后进入程序 
}

//银行界面
void BankMenu()
{
	system("cls");
	system("color f9");
	cout << "                    ===========================================================================" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                          ------我的银行------                           |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                             输入1：开始模拟			      |" << endl;
	cout << "                    |                             输入2：退出系统			      |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    ===========================================================================" << endl;
}

//银行菜单方法
void BankStartMenu()
{
	int select = 0;

	int open_time;//银行开门时间 
	int closed_time;//银行关闭时间 

	cout << "                                        请输入银行开始营业的时间：";
	cin >> open_time;//设置银行开始营业时间 （小时）
	cout << endl;
	cout << "                                        请输入银行结束营业的时间：";
	cin >> closed_time;//设置银行结束营业时间（小时）


	while (select != 2)
	{
		BankMenu();//显示银行菜单 
		cout << "                                        请输入你的选择：      ";
		cin >> select;//输入选择

		switch (select)
		{
		case 1:
			system("cls");//清屏然后开始银行模拟 
			startWorking(open_time, closed_time);//开始模拟银行工作
			break;

		case 2:
			system("cls");//清屏然后结束 
			cout << "                                              欢迎下次光临                                  " << endl;
			break;

		default:
			cout << "                                  输入不合法，请输入1~3" << endl;

			break;
		}
	}

	return;
}
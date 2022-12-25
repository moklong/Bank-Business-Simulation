/*
Day1(12.23)：创建项目，项目主要模块：银行类和客户类，以及相关接口的定义与实现

Day2(12.24)：对银行业务模拟主要功能函数进行梳理并且申明，完善了一小部分
                       对各个类模块的函数进行完善

Day3(12.25)：随机创建客户,客户相关信息打印输出，主要功能函数的基本实现

Day4(12.26)：对大致结构进行完善，Debug以及对于细节优化
*/

#include"Menu.h"
//#include"Bank.h"
//#include"Banksystem.h"
//#include"Client.h"
//#include"LinkedQueue.h"

using namespace std;

int main()
{
	srand((int)time(NULL));  //用时间作为种子对随机数进行操作

	welcome();

	try
	{
		BankStartMenu();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	return 0;
}
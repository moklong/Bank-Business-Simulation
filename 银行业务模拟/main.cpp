/*
Day1(12.23)��������Ŀ����Ŀ��Ҫģ�飺������Ϳͻ��࣬�Լ���ؽӿڵĶ�����ʵ��

Day2(12.24)��������ҵ��ģ����Ҫ���ܺ�������������������������һС����
                       �Ը�����ģ��ĺ�����������

Day3(12.25)����������ͻ�,�ͻ������Ϣ��ӡ�������Ҫ���ܺ����Ļ���ʵ��

Day4(12.26)���Դ��½ṹ�������ƣ�Debug�Լ�����ϸ���Ż�
*/

#include"Menu.h"
//#include"Bank.h"
//#include"Banksystem.h"
//#include"Client.h"
//#include"LinkedQueue.h"

using namespace std;

int main()
{
	srand((int)time(NULL));  //��ʱ����Ϊ���Ӷ���������в���

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
#include"Menu.h"
#include"Bank.h"
#include"Banksystem.h"
#include"Client.h"
#include"LinkedQueue.h"

//��ʼ����
void welcome()
{
	system("color f9");

	cout << "                    ***---------------------------------------------------------------------***" << endl;
	cout << "                                                                                               " << endl;
	cout << "						��ӭ����					" << endl;

	Sleep(1500);//��˯1.5��

	cout << "						�ҵ�����					" << endl;
	cout << "                                                                                               " << endl;
	cout << "                    ***---------------------------------------------------------------------***" << endl;

	Sleep(1500);//��˯1.5��

	cout << "                    ===========================================================================" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                       �����̶���ʱ��                                  *" << endl;
	cout << "                    *                       ʱ�佫�޷����ı�                                  *" << endl;

	cout << "                    *                       �������ı�ʹʱ�䣬������˳�                    *" << endl;
	cout << "                    *                       ������������   	  		              *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    ===========================================================================" << endl;

	Sleep(1000);//1��������� 
}

//���н���
void BankMenu()
{
	system("cls");
	system("color f9");
	cout << "                    ===========================================================================" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                          ------�ҵ�����------                           |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                             ����1����ʼģ��			      |" << endl;
	cout << "                    |                             ����2���˳�ϵͳ			      |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    |                                                                         |" << endl;
	cout << "                    ===========================================================================" << endl;
}

//���в˵�����
void BankStartMenu()
{
	int select = 0;

	int open_time;//���п���ʱ�� 
	int closed_time;//���йر�ʱ�� 

	cout << "                                        ���������п�ʼӪҵ��ʱ�䣺";
	cin >> open_time;//�������п�ʼӪҵʱ�� ��Сʱ��
	cout << endl;
	cout << "                                        ���������н���Ӫҵ��ʱ�䣺";
	cin >> closed_time;//�������н���Ӫҵʱ�䣨Сʱ��


	while (select != 2)
	{
		BankMenu();//��ʾ���в˵� 
		cout << "                                        ���������ѡ��      ";
		cin >> select;//����ѡ��

		switch (select)
		{
		case 1:
			system("cls");//����Ȼ��ʼ����ģ�� 
			startWorking(open_time, closed_time);//��ʼģ�����й���
			break;

		case 2:
			system("cls");//����Ȼ����� 
			cout << "                                              ��ӭ�´ι���                                  " << endl;
			break;

		default:
			cout << "                                  ���벻�Ϸ���������1~3" << endl;

			break;
		}
	}

	return;
}
#include <iostream>
#include <math.h>
using namespace std;

//��ǰ��Ǯ�⣬��ֵ�Լ���Ӧ����
int single_money[7] = { 1,2,5,10,20,50,100 };
int number_money[7] = { 2,5,0,3,4,0,4 };

//ÿ����ֵʹ��̰���㷨����Ҫʹ�õ�����
int count[7] = {};

int total_count;

int tanxin(int money)
{
	if (money >= 0)   //����һ������淶������
	{
		for (int i = 6; i >= 0; i--)
		{
			count[i] = min(number_money[i], money / single_money[i]);
			money = money - count[i] * single_money[i];
		}
		return 0;
	}
	else
	{
		return money;
	}

}


int main(int argc, char** argv)
{
	int money;
	cout << "Please input the amount of money:";
	cin >> money;
	if (!tanxin(money))
	{
		cout << "̰�����Ž��Ϊ��" << endl;
		cout << "100Ԫ��" << count[6] << "��" << endl;
		cout << "50Ԫ��" << count[5] << "��" << endl;
		cout << "20Ԫ��" << count[4] << "��" << endl;
		cout << "10Ԫ��" << count[3] << "��" << endl;
		cout << "5Ԫ��" << count[2] << "��" << endl;
		cout << "2Ԫ��" << count[1] << "��" << endl;
		cout << "1Ԫ��" << count[0] << "��" << endl;
	}
	else
	{
		cout << "Ops, Wrong number~";
	}
	system("pause");
	return 0;
}


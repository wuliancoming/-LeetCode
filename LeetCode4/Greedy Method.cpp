#include <iostream>
#include <math.h>
using namespace std;

//当前的钱库，面值以及对应数量
int single_money[7] = { 1,2,5,10,20,50,100 };
int number_money[7] = { 2,5,0,3,4,0,4 };

//每种面值使用贪心算法后需要使用的张数
int count[7] = {};

int total_count;

int tanxin(int money)
{
	if (money >= 0)   //考虑一下输入规范的问题
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
		cout << "贪心最优结果为：" << endl;
		cout << "100元：" << count[6] << "张" << endl;
		cout << "50元：" << count[5] << "张" << endl;
		cout << "20元：" << count[4] << "张" << endl;
		cout << "10元：" << count[3] << "张" << endl;
		cout << "5元：" << count[2] << "张" << endl;
		cout << "2元：" << count[1] << "张" << endl;
		cout << "1元：" << count[0] << "张" << endl;
	}
	else
	{
		cout << "Ops, Wrong number~";
	}
	system("pause");
	return 0;
}


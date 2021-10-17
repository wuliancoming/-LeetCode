#include <iostream>

using namespace std;

typedef int ElementType;

const int length=100000;

int main()

{
int array[len];

int num;

for(int i=0;i<len;i++)

array[i]=0;

while(1)

{
cout<<"请输入要增加的数:-1为结束"<<endl;

cin>>num;

if(num<=-1) break;

array[num]++;

}

cout<<"请输入需要查找的数字:;

cin>>num;

if(array[num]==0) cout<<"not found!"<<endl;

else cout<<"搜索成功，共出现"<<array[num]<<"次“<<endl;

return 0;

}

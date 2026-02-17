#include<iostream>
using namespace std;
int main()
	{
	int marks,grade;
	cout<<"enter a marks:"<<marks<<endl;
	cin>>marks;
	if(marks>90)
{
	cout<<"A+"<<grade<<endl;
	}
	else if(marks>80)
	{
		cout<<"A"<<grade<<endl;
	}
	else if(marks>70)
{
	cout<<"B+"<<grade<<endl;
}
else if(marks<60)
{
	cout<<"B"<<grade<<endl;
}
else if(marks<50)
{
	cout<<"C"<<grade<<endl;
}
else
{
	cout<<"invalid grade"<<grade<<endl;
}
return 0;
}

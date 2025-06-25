#include<iostream>
using namespace std;
int main()
{
	int a,b,c,total,average;
	cout<<"Enter the marks of PF\n";
	cin>>a;
	cout<<"Enter the marks of OOP\n";
	cin>>b;
	cout<<"Enter the marks of DSA\n";
	cin>>c;
	total=a+b+c;
	cout<<"The total marks are :"<<total<<endl;
	average=(a+b+c)/3;
	cout<<"The average is :"<<average<<endl;
	if(total>=80)
	{
		cout<<"The grade is A";
	}
	else if(total>=70)
	{
		cout<<"The grade is B";
	}
	else if(total>=60)
	{
		cout<<"The grade is C";
	}
	else
	{
		cout<<"The grade is F";
	}
	return 0;
}
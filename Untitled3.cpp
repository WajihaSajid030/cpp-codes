#include<iostream>
#include<string>
using namespace std;
int main()
{
	string name;
	int age;
	float gpa;
	cout<<"Enter your name\n";
	cin>>name;
	cout<<"Enter your age\n";
	cin>>age;
	cout<<"Enter your GPA\n";
	cin>>gpa;
	if(age>=18&&gpa>=2.5)
	{
		cout<<"You are eligible to apply";
	}
	else
	{
		cout<<"You are not eligible";
	}
	return 0;
}
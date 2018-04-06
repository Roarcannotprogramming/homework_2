#include<iostream>
#include<ctime>
#include<strstream>
#include<stdlib.h>
#include<string>
using namespace std;
int flag = 1;//全局变量，
int function(int n)//随机生成1至n的整数
{
	int random;
	int low = 1, high = n;
	if (flag)
	{
		flag = 0;
		srand((unsigned)time(NULL));//种子
	}
	random = rand()% (high - low+1) + low;//生成随机数
	return random;
	
}
int max(int a, int b)//返回两个整数中较大的整数
{
	int h=a >=b ? a : b;
	return h;
}
int min(int a, int b)//返回两个整数中较小的整数
{
	int l = a <=b ? a : b;
	return l;
}
string fraction()//生成真分数
{
	int temp1 = function(100);//调用function函数随机生成两个随机整数
	int temp2 = function(100);
	int high = min(temp1, temp2);//比较两个整数的大小，其中较大的整数做分母，较小的整数做分子
	int low = max(temp1, temp2);
	strstream tra,ss;//将分子分母从int型转换为string型
	string up, down;
	tra << high;
	tra >> up;
	ss << low;
	ss >> down;
	string fra;
	high != low ? fra = up + "\\" + down : fra = 1;//将分子分母连接成真分数
	return fra;
}
int main()
{
	int integer1, integer2;
	string first, second;//四则运算的第一个运算数和第二个运算数
	int ch1, ch2, ch3;//switch语句的选项
	char sign;//运算符号
	int times = 30;//题目数
	for (int i = 1;i <= times;i++)
	{
		ch1 = function(4);//随机生成运算符号
		switch (ch1)
		{
		case 1:sign = '+';break;
		case 2:sign = '-';break;
		case 3:sign = '*';break;
		case 4:sign = '/';break;
		default:cout << "有错误！" << endl;break;
		}
		ch2 = function(3);//四则运算题目的三种情况
		switch (ch2)
		{
		case 1://整数和整数
		{
			strstream ss, cc;
			integer1 = function(100);
			ss << integer1;
			ss >> first;
			integer2 = function(100);
			cc << integer2;
			cc >> second;
		}break;
		case 2://整数和真分数
		{
			strstream kk;
			integer1 = function(100);
			kk << integer1;
			kk >> first;
			second = fraction();
		}break;
		case 3://真分数和真分数
		{
			first = fraction();
			second = fraction();
		}break;
		default:cout << "有错误！" << endl;break;
		}
		ch3 = function(2);//输出的两种情况
		switch (ch3)
		{
		case 1:cout <<"("<< first <<")"<< sign << "("<<second<<")" << "=" << endl;break;
		case 2:cout << "(" << second << ")" << sign << "(" << first<< ")" << "=" << endl;break;
		default:cout << "有错误！" << endl;break;
		}
	}
	

	system("pause");
	return 0;
}
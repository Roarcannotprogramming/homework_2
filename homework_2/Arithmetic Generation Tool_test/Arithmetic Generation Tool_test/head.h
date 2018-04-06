#pragma once
#include<iostream>
#include<ctime>
#include<strstream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#define random(l,h) (rand()%(h-l+1)+l)//宏定义
#define maxsize 1000
using namespace std;
extern int flag;
/*stack.cpp*/
struct Fraction
{
	int up, down;
	string high, low;
};
void trans(string exp, char postexp[]);
Fraction compvalue(char postexp[]);//计算后缀表达式的值
/*fraction.cpp*/
int gcd(int a, int b);//求a,b的最大公约数
int max(int a, int b);
int min(int a, int b);
Fraction fraction(int up, int down);//生成分数
Fraction fra(int d, int u);//生成真分数;
Fraction reduction(Fraction result);//分数的化简
Fraction add(Fraction f1, Fraction f2);//分数的加法
Fraction minus1(Fraction f1, Fraction f2);//分数的减法
Fraction multi(Fraction f1, Fraction f2);//分数的乘法
Fraction divide(Fraction f1, Fraction f2);//分数的除法
void ShowResult(Fraction f);//输出分数
string FraToString(Fraction f);//将分数转换为string类型
/*yunsuan.cpp*/
int suiji(int down, int up);//随机生成1至n的整数
bool is_unique(string str, vector <string> s);//判断生成的运算式是否重复
void yunsuan(int time, int low, int high, int fl1, int fl2, int fl3);

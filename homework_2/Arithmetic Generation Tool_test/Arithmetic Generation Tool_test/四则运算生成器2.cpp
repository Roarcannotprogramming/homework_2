#include<iostream>
#include<ctime>
#include<strstream>
#include<stdlib.h>
#include<string>
#include<vector>
#define random(l,h) (rand()%(h-l+1)+l)//宏定义
using namespace std;
int flag = 1;//全局变量，

int suiji(int down,int up)//随机生成1至n的整数
{
	int low = down, high = up;
	if (flag)
	{
		flag = 0;
		srand((unsigned)time(NULL));//种子
	}
	//random = rand() % (high - low + 1) + low;//生成随机数
    int result=random(down, up);
	return result;

}
int max(int a, int b)//返回两个整数中较大的整数
{
	int h = a >= b ? a : b;
	return h;
}
int min(int a, int b)//返回两个整数中较小的整数
{
	int l = a <= b ? a : b;
	return l;
}
string fraction(int d,int u)//生成真分数
{
	int temp1 = suiji(d,u);//调用function函数随机生成两个随机整数
	int temp2 = suiji(d,u);
	int high = min(temp1, temp2);//比较两个整数的大小，其中较大的整数做分母，较小的整数做分子
	int low = max(temp1, temp2);
	strstream tra, ss;//将分子分母从int型转换为string型
	string up, down;
	tra << high;
	tra >> up;
	ss << low;
	ss >> down;
	string fra;
	high != low ? fra = up + "\\" + down : fra = "1";//将分子分母连接成真分数
	return fra;
}
bool is_unique(string str, vector <string> s)//判断生成的运算式是否重复
{
	int count = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (str != s[i])
		{
			count++;
		}
		else break;
	}
	bool flag0 = count == s.size() ? true : false;
	return flag0;
}
void yunsuan(int time,int low,int high,int fl1,int fl2,int fl3,int fl4,int fl5)//根据参数要求生成四则运算式
{
	int integer1, integer2;
	int ch1, ch2, ch3,ch4;//switch语句的选项
	//int j=1,i=0;
	char sign;//运算符号
	int times = time;//题目数
	vector <string> str;//str用来保存生成的题目
	for (int i = 1;i <= times;)
	{
		int flag4 = 1;//flag4用来标记运算式是否是刚开始生成
		string first, second, cal ;//四则运算的第一个运算数和第二个运算数
		int number = suiji(1, 9);//number为参与运算的参数个数
		for (int j = 1;j <= number;)
		{
			//-------------------------------------------------------------------------------------
			if (fl1 == 1)//允许乘除发参与运算的情况
			{
				ch1 = suiji(1, 4);//随机生成运算符号
				switch (ch1)
				{
				case 1:sign = '+';break;
				case 2:sign = '-';break;
				case 3:sign = '*';break;
				case 4:sign = '/';break;
				default:cout << "有错误！" << endl;break;
				}
			}
			else//不允许乘除法参与运算的情况
			{
				ch1 = suiji(1, 2);//随机生成运算符号
				switch (ch1)
				{
				case 1:sign = '+';break;
				case 2:sign = '-';break;
				default:cout << "有错误！" << endl;break;
				}
			}
			//-------------------------------------------------------------------------------------
			if (fl4 == 1)//允许真分数参与运算
			{
				ch2 = suiji(1, 3);//四则运算题目的三种情况
				switch (ch2)
				{
				case 1://整数和整数
				{
					strstream ss, cc;
					integer1 = suiji(low, high);
					ss << integer1;//将int型变量转换为string型变量
					ss >> first;
					integer2 = suiji(low, high);
					cc << integer2;
					cc >> second;
				}break;
				case 2://整数和真分数
				{
					strstream kk;
					integer1 = suiji(low, high);
					kk << integer1;
					kk >> first;
					second = fraction(low, high);
				}break;
				case 3://真分数和真分数
				{
					first = fraction(low, high);
					second = fraction(low, high);
				}break;
				default:cout << "有错误！" << endl;break;
				}
			}
			else//不允许真分数参与运算
			{
				strstream ss, cc;
				integer1 = suiji(low, high);
				ss << integer1;//将int型变量转换为string型的变量
				ss >> first;
				integer2 = suiji(low, high);
				cc << integer2;
				cc >> second;
			}
			//-------------------------------------------------------------------------------------
			if (fl2 == 1)//允许负数参与运算
			{
				ch3 = suiji(1, 3);
				switch (ch3)//根据随机情况添加负号
				{
				case 1:first = "(" + first + ")";second = "(" + second + ")";break;
				case 2:first = "(-" + first + ")";second = "(" + second + ")";break;
				case 3:first = "(-" + first + ")";second = "(-" + second + ")";break;
				}
			}
			else//不允许负数参与运算
			{
				first = "(" + first + ")";
				second = "(" + second + ")";
			}

			//-------------------------------------------------------------------------------------
			if (fl3 == 1)//允许括号（【】）参与运算
			{
				ch4 = suiji(1, 4);
				switch (ch4)
				{
				case 1:
				{
					if (flag4 == 1)//flag4为1表示运算式还未生成前两个运算数
					{
						cal = first + sign + second;
						flag4 = 0;
					}
					else
					{
						cal = cal + sign + first;//将以生成的运算式个新生成的运算数连接起来
					}
				}break;
				case 2:
				{
					if (flag4 == 1)
					{
						cal = second + sign + first;
						flag4 = 0;
					}
					else
					{
						cal = second + sign + cal;
					}
				}break;
				case 3:
				{
					if (flag4 == 1)
					{
						cal = "[" + first + sign + second + "]";//添加括号【】的情况
						flag4 = 0;
					}
					else
					{
						cal = "[" + cal + sign + first + "]";
					}
				}break;
				case 4:
				{
					if (flag4 == 1)
					{
						cal = "[" + second + sign + first + "]";
						flag4 = 0;
					}
					else
					{
						cal = "[" + second + sign + cal + "]";
					}
				}break;
				default:cout << "有错误！" << endl;break;
				}
			}
			else//不允许括号（【】）参与运算
			{
				ch4 = suiji(1, 2);//输出的两种情况
				switch (ch4)
				{
				case 1:
				{
					if (flag4 == 1)
					{
						cal = first + sign + second;
						flag4 = 0;
					}
					else
					{
						cal = cal + sign + first;
					}
				}break;
				case 2:
				{
					if (flag4 == 1)
					{
						cal = second + sign + first;
						flag4 = 0;
					}
					else
					{
						cal = second + sign + cal;
					}
				}break;
				default:cout << "有错误！" << endl;break;
				}
			}
			j++;
		}
		//------------------------------------------------------------------------------
		if (str.empty())//若sr为空，则将第一个生成的运算式添加到vector中
		{
			str.push_back(cal);
			cout << "(" << i << ")." << cal << "=" << endl;
			i++;
		}
		if (is_unique(cal, str))//判断生成的运算式和之前已经生成的运算式是否重复
		{
			str.push_back(cal);//将生成的运算式添加到str中
			cout << "(" << i << ")." << cal << "=" << endl;
			i++;
		}
		else {}
	}
}
int main()
{
	cout << "请输入题目数(1~100)：";
	int times,down,up,flag1,flag2,flag3,flag4,flag5=1;
	cin >> times;//times至题目数
	cout << "请输入数值绝对值范围:";
	cin >> down >> up;//[down,up]为运算数范围
	cout << "是否允许乘除发参与运算（y/n）:";
	char yn1;
	cin >> yn1;
	yn1 == 'y' || yn1=='Y' ? flag1 = 1 : flag1 = 0;
	cout << "是否允许负数参与运算（y/n）:";//flag1判断是否允许乘除法参与运算
	char yn;
	cin >> yn;
	yn == 'y'||yn=='Y' ? flag2 = 1 : flag2 = 0;//flag2判断是否允许负数
	cout << "是否允许括号（[]）参与运算（y/n）:";
	char yn2;
	cin >> yn2;
	yn2 == 'y'||yn2=='Y' ? flag3 = 1 : flag3 = 0;//flag3判断是否允许括号参与运算
	cout << "是否允许真分数参与运算（y/n）：";
	char yn3;
	cin >> yn3;
	yn3 == 'y'||yn3=='Y' ? flag4 = 1 : flag4 = 0;//flag4判断是否允许真分数参与运算
	yunsuan(times,down,up,flag1,flag2,flag3,flag4,flag5);
	system("pause");
	return 0;
}
#include"head.h"
int flag = 1;
int suiji(int down, int up)//随机生成1至n的整数
{
	int low = down, high = up;
	if (flag)
	{
		flag = 0;
		srand((unsigned)time(NULL));//种子
	}
	int result = random(down, up);
	return result;

}
bool is_unique(string str, vector <string> s)//判断生成的运算式是否重复
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (str!=s[i])
		{
			count++;
		}
		else break;
	}
	bool flag0 = count == s.size() ? true : false;
	return flag0;
}
void yunsuan(int time, int low, int high, int fl1, int fl2, int fl3)//根据参数要求生成四则运算式
{
	int integer1, integer2;
	int ch1, ch2, ch3, ch4;//switch语句的选项
	char sign;//运算符号
	int times = time;//题目数
	vector <string> str;//str用来保存生成的题目
	int right = 0, wrong = 0;
	for (int i = 1; i <= times;)
	{
		int flag4 = 1;//flag4用来标记运算式是否是刚开始生成
		string first, second, cal;//四则运算的第一个运算数和第二个运算数
		int number = suiji(1, 9);//number为参与运算的参数个数
		for (int j = 1; j <= number;)
		{
			//-------------------------------------------------------------------------------------
			if (fl1 == 1)//允许乘除发参与运算的情况
			{
				ch1 = suiji(1, 4);//随机生成运算符号
				switch (ch1)
				{
				case 1:sign = '+'; break;
				case 2:sign = '-'; break;
				case 3:sign = '*'; break;
				case 4:sign = '/'; break;
				default:cout << "有错误！" << endl; break;
				}
			}
			else//不允许乘除法参与运算的情况
			{
				ch1 = suiji(1, 2);//随机生成运算符号
				switch (ch1)
				{
				case 1:sign = '+'; break;
				case 2:sign = '-'; break;
				default:cout << "有错误！" << endl; break;
				}
			}
			//-------------------------------------------------------------------------------------
			if (fl3 == 1)//允许真分数参与运算
			{
				ch2 = suiji(1, 3);//四则运算题目的三种情况
				switch (ch2)
				{
				case 1://整数和整数
				{
					strstream si, so;
					integer1 = suiji(low, high);
					si << integer1; si >> first;
					integer2 = suiji(low, high);
					so << integer2; so >> second;
				}break;
				case 2://整数和真分数
				{
					strstream ss;
					integer1 = suiji(low, high);
					ss << integer1; ss >> first;
					Fraction f = reduction(fra(low, high));
					second = "(" + f.high + "\\" + f.low + ")";
				}break;
				case 3://真分数和真分数
				{
					Fraction f1 = reduction(fra(low, high));
					Fraction f2 = reduction(fra(low, high));
					first = "(" + f1.high + "\\" + f1.low + ")";
					second = "(" + f2.high + "\\" + f2.low + ")";
				}break;
				default:cout << "有错误！" << endl; break;
				}
			}
			else//不允许真分数参与运算
			{
				strstream si, so;
				integer1 = suiji(low, high);
				si << integer1; si >> first;
				integer2 = suiji(low, high);
				so << integer2; so >> second;
			}
			//-------------------------------------------------------------------------------------
			if (fl2 == 1)//允许括号（【】）参与运算
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
				default:cout << "有错误！" << endl; break;
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
				default:cout << "有错误！" << endl; break;
				}
			}
			j++;
		}
		//------------------------------------------------------------------------------
		if (str.empty())//若sr为空，则将第一个生成的运算式添加到vector中
		{
			str.push_back(cal);
			cout << "(" << i << ")." << cal << "=";

			string answer;
			cin >> answer;
			char postexp[maxsize];
			trans(cal, postexp);
			Fraction re = compvalue(postexp);
			string result = FraToString(re);
			if (answer == result)
			{
				cout << "正确！" << endl;
				right++;
			}
			else
			{
				cout << "错误！，正确答案为:" << result << endl;
				wrong++;
			}
			i++;
		}
		if (is_unique(cal, str))//判断生成的运算式和之前已经生成的运算式是否重复
		{
			str.push_back(cal);//将生成的运算式添加到str中
			cout << "(" << i << ")." << cal << "=";
			string answer;
			cin >> answer;
			char postexp[maxsize];
			trans(cal, postexp);
			Fraction re = compvalue(postexp);
			string result = FraToString(re);
			if (answer == result)
			{
				cout << "正确！" << endl;
				right++;

			}
			else
			{
				cout << "错误！，正确答案为:" << result << endl;
				wrong++;
			}
			i++;
		}
		else {}
	}
	cout << "**********************************************************************************" << endl;
	cout << "你做对了" << right << "道题，做错了" << wrong << "道题" << endl;
}
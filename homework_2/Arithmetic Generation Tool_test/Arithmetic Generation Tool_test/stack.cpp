#include"head.h"
struct
{
	char data[maxsize];//存放运算符
	int top;//栈顶指针
}op;//定义运算符栈
void trans(string exp, char postexp[])//exp[]为算数表达式，postexp[]为后缀表达式
{
	char ch;
	int i = 0, j = 0;//i作为exp的下标，j作为postexp的小标
	op.top = -1;
	ch = exp[i];
	i++;
	while (ch != '\0')//exp表达式未扫描完时循环
	{
		switch (ch)
		{
		case'['://判定为左括号
		{
			op.top++;
			op.data[op.top] = ch;
		}break;
		case']'://判定为右括号，此时将’[‘之前的运算符依次出栈并存放到postexp中
		{
			while (op.data[op.top] != '[')
			{
				postexp[j] = op.data[op.top];
				j++;
				op.top--;
			}
			op.top--;//将’[‘删除
		}break;
		case'+'://为’+‘或’-‘时，其优先级不大于栈顶的任何运算符，直到’]‘为止
		case'-':
		{
			while (op.top != -1 && op.data[op.top] != '[')
			{
				postexp[j] = op.data[op.top];
				j++;
				op.top--;
			}
			op.top++;
			op.data[op.top] = ch;
		}break;
		case'*'://为’*‘或’/’时，其优先级不大于栈顶为‘*’或‘/‘的优先级，直到’['
		case'/':
		{
			while (op.top != -1 && op.data[op.top] != '[' && (op.data[op.top] == '*' || op.data[op.top] == '/'))
			{
				postexp[j] = op.data[op.top];
				j++;
				op.top--;
			}
			op.top++;
			op.data[op.top] = ch;
		}break;
		case' ':break;//过滤掉空格
		case'('://将分数当成一个整体放到postexp中
		{
			while (ch != ')')
			{
				postexp[j]=ch;
				j++;
				ch = exp[i];
				i++;
			}
			postexp[j]=ch; j++;//将')'放到postexp中
		}break;
		default:
		{
			while (ch >= '0'&&ch <= '9')//判定为数字
			{
				postexp[j] = ch;
				j++;
				ch = exp[i];
				i++;
			}
			i--;
			postexp[j] = '#';//用#标示一个数值的结束
			j++;
		}
		}
		ch = exp[i];
		i++;
	}
	while (op.top != -1)//此时exp扫描完毕，栈不空时出栈并存放到postexp中
	{
		postexp[j] = op.data[op.top];
		j++;
		op.top--;
	}
	postexp[j] = '\0';//给postexp表达式添加结束标识
}
struct
{
    Fraction data[maxsize];//存放数值
	int top;//栈顶指针
}st;
 Fraction compvalue(char postexp[])//计算后缀表达式的值
{
	double d;
	char ch;
	int i = 0;//postexp的下标
	st.top = -1;
	ch = postexp[i];
	i++;
	while (ch != '\0')//postexp字符串未扫描完事完成循环
	{
		switch (ch)
		{
		case'+':
		{
			st.data[st.top - 1] = add(st.data[st.top - 1], st.data[st.top]);
			st.top--;
		}break;
		case'-':
		{
			st.data[st.top - 1] = minus1(st.data[st.top - 1], st.data[st.top]);
			st.top--;
		}break;
		case'*':
		{
			st.data[st.top - 1] = multi(st.data[st.top - 1], st.data[st.top]);
			st.top--;
		}break;
		case'/':
		{
			st.data[st.top - 1] = divide(st.data[st.top - 1], st.data[st.top]);
			st.top--;
		}break;
		case'(':
		{
			double high = 0, low = 0;
			ch = postexp[i]; i++;//删除‘（‘
			while (ch != '\\')
			{
				high = 10 * high + ch - '0';
				ch = postexp[i];
				i++;
			}
			ch = postexp[i]; i++;//删除’\’
			while (ch != ')')
			{
				low = 10 * low + ch - '0';
				ch = postexp[i];
				i++;
			}
			st.top++;
			Fraction re = fraction(high, low);
			st.data[st.top] = re;
		}break;
		default:
		{
			d = 0;
			while (ch >= '0'&&ch <= '9')//将数字字符转化为对应的数值存放到d中
			{
				d = 10 * d + ch - '0';
				ch = postexp[i];
				i++;
			}
			st.top++;
			Fraction re = fraction(d, 1);
			st.data[st.top] = re;
		}
		}
		ch = postexp[i];
		i++;
	}
	return st.data[st.top];
}
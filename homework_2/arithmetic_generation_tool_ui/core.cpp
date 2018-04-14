#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <Regex>
#include "core.h"
#include <math.h>

#include "stdlib.h"

bool fomularCore::isOperate(char ch)
{
	auto it = find(ops.begin(), ops.end(), ch);
	if (it == ops.end())
		return false;
	else
		return true;
}

int fomularCore::Rank(char s)
{
	switch (s)
	{
	case '#':return -2;
	case '\0':return -1;
	case '(':return 0;
	case ')':return 0;//左右括号优先级小是为了不被其余任何运算符挤出
	case '+':
	case '-':return 1;//低优先级将挤出高优先级
	case '*':
	case '%':
	case '/':return 2;
	case '^':return 3;
	default:return 4;
	}
}

double fomularCore::CalcNum(double a, double b, char c)
{
	switch (c)
	{
	case '+':return (a + b);
	case '-':return (a - b);
	case '*':return (a*b);
	case '/':return a / b;
	case '%':return (int)a % (int)b;
	case '^':return pow(a, b);
	default:return a;
	}
}

//从string中读取一个double数并push
void fomularCore::doublepush(stack<double> & st, string exp, int & pos)
{
	string fl;
	char c;

	while (!isOperate(exp[pos - 1]) && exp[pos - 1] != '\0')
	{
		//pos is the next position
		c = exp[pos - 1];
		fl.push_back(c);
		pos++;
	}
	pos--;
	st.push(atof(fl.c_str()));
}

double fomularCore::arthimetic(string & exp)
{

	//OPTR是运算符栈，OPEN是运算数栈
	exp.push_back('\0');
	stack<char> OPTR; OPTR.push('#');
	stack<double> OPEN;
	char ch = 'a', ch2;//'a'to init set ch
	double c1, c2;
	int pos = 0;



	while (ch != '\0' || OPTR.top() != '#')
	{
		if (ch != '\0')ch = exp[pos++];

		if (pos == 1 && ch == '+') { pos++; continue; }
		if (pos == 1 && ch == '-') { exp.insert(0, 1, '0'); pos--; continue; }
		//to deal with  '+8+1' '-8+2'

		if (!isOperate(ch) && ch != '\0')
		{
			//pos is the next position
			if (ch == ' ');//skip space
			else doublepush(OPEN, exp, pos);
			continue;
		}
		switch (ch)
		{
		case '(':OPTR.push(ch); break;
		case ')':
			ch2 = OPTR.top();
			while (ch2 != '(')
			{
				if (OPEN.empty())
					throw "wrong fomular format";
				c1 = OPEN.top(); OPEN.pop();
				if (OPEN.empty())
					throw "wrong fomular format";
				c2 = OPEN.top(); OPEN.pop();
				OPEN.push(CalcNum(c2, c1, ch2));
				OPTR.pop();
				ch2 = OPTR.top();
			}
			OPTR.pop();
			break;
		default:
			ch2 = OPTR.top();
			while (Rank(ch2) >= Rank(ch))
			{
				OPTR.pop();
				if (OPEN.empty())
					throw "wrong fomular format";
				c1 = OPEN.top(); OPEN.pop();
				if (OPEN.empty())
					throw "wrong fomular format";
				c2 = OPEN.top(); OPEN.pop();
				OPEN.push(CalcNum(c2, c1, ch2));
				ch2 = OPTR.top();
			}
			if (ch != '\0')OPTR.push(ch);
			break;
		}//switch
	}//while
	 //cout << ' ' << OPEN.top();
	return OPEN.top();
}

int fomularCore::findMultiple(string instr)
{
	string tpnum;
	int mulNum = 1;
	int inerMul = 1;
	int lenstr = instr.size();
	int bacNum = 0;
	for (int i = 0; i < lenstr; i++)
	{
		if (instr[i] == '/')
		{
			if (instr[i + 1] == '(')
			{
				i++;

				while (i <= lenstr)
				{
					if (instr[i] == '(')bacNum++;
					if (instr[i] == ')')bacNum--;
					if (instr[i] == '/')inerMul *= findMultiple(instr.substr(i));

					tpnum.push_back(instr[i]);
					if (bacNum == 0)break;
					i++;
				}
			}
			else
			{
				while (isNum(instr[i + 1]) && i + 1 <= lenstr)
				{
					tpnum.push_back(instr[i + 1]);
					i++;
				}

			}
			tpnum.insert(0, 1, '(');
			mulNum *= int(arthimetic(tpnum.append(")*").append(to_string(int(inerMul)))));//求得最大的分母，之后再约
			tpnum.clear();
		}
	}
	if (mulNum == 0 || mulNum>MaxRange)
		return 1;
	return mulNum;
}
bool fomularCore::withDot(string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			return true;
	}
	return false;
}
int fomularCore::gcd(int a, int b)
{
	if (b != 0)
		return gcd(b, a % b);
	else
		return a;
}

bool fomularCore::computeTree(fomularNode* ro, double &res)//计算表达式二叉树，若不违反非负，返回res结果
{
	double re1 = 0, re2 = 0;
	bool b1, b2;
	if (ro == NULL) return false;
	if (ro->chFlag == true)
	{
		b1 = computeTree(ro->lchild, re1);
		b2 = computeTree(ro->rchild, re2);
		res = CalcNum(re1, re2, char(ro->value));
		if (res < 0 || res>MaxRange)return false;
		else return b1 && b2;
	}
	else
	{
		res = ro->value;
		return true;
	}
}

//随机生成原始表达式，个数为expNum
vector<string> fomularCore::geneExp(int expNum)
{
	vector<string> res;
	string temp;
	int num, opch;
	string numstr;
	int loc1, loc2;//括号位置
	int opnum, bracketNum;
	bool isPower = false;

	for (int i = 0; i < expNum; i++)
	{
		opnum = random(1, maxopNum);//选定运算符个数

		for (int j = 0; j < opnum; j++)
		{
			if (isPower == false)
			{
				num = random(1, range);//暂时不管0.。
				numstr = to_string(num);
			}
			else
			{
				num = random(1, 5);//暂时不管0.。
				numstr = to_string(num);
				isPower = false;
			}
			opch = ops[random(0, ops.size() - 3)];//选择运算符
			if (char(opch) == '^')
				isPower = true;
			temp.append(numstr);
			temp.push_back(opch);
		}
		num = random(1, range);//暂时不管0.。
		numstr = to_string(num);
		temp.append(numstr);

		bracketNum = random(1, opnum);//选定括号对数

		while (bracketNum-- >0)
		{
			loc1 = random(0, temp.size() - 1);
			loc2 = random(loc1 + 1, temp.size());//括号位置

			while (loc1 != 0 && (!isNum(temp[loc1]) || !isOperate(temp[loc1 - 1])))
			{
				loc1--;
			}
			temp.insert(loc1, 1, '(');

			while (loc2 != temp.size() && (!isNum(temp[loc2 - 1]) || !isOperate(temp[loc2])))
			{
				loc2++;
			}//移动括号到合适位置并插入
			temp.insert(loc2, 1, ')');
		}


		res.push_back(temp);
		temp.clear();

	}
	return res;
}

bool fomularCore::toPostTree(vector<string> & fomus)
{
	vector<string> res;

	string exp, numstr;
	stack<char> OPTR; //运算符栈
	stack<fomularNode*> OPEN;//结果栈
	fomularNode *node1, *node2, *tempNode;


	for (size_t i = 0; i < fomus.size(); i++)
	{
		exp = fomus[i];
		//exp = "2+3"; //测试输入
		//OPTR是运算符栈，OPEN是运算数栈
		exp.push_back('\0');
		OPTR.push('#');

		char ch = 'a', ch2;//'a'to init set ch
		int pos = 0;


		while (ch != '\0' || OPTR.top() != '#')
		{
			if (ch != '\0')ch = exp[pos++];

			if (pos == 1 && ch == '+') { pos++; continue; }
			if (pos == 1 && ch == '-') { exp.insert(0, 1, '0'); pos--; continue; }
			//to deal with  '+8+1' ‘-8+4’

			if (!isOperate(ch) && ch != '\0')
			{
				//pos is the next position
				if (ch == ' ');//skip space
				else
				{
					while (!isOperate(exp[pos - 1]) && exp[pos - 1] != '\0')
					{
						numstr.push_back(exp[pos - 1]);
						pos++;
					}
					pos--;
					tempNode = new fomularNode(atoi(numstr.c_str()), false);
					OPEN.push(tempNode);
					numstr.clear();
				}
				continue;
			}
			switch (ch)
			{
			case '(':OPTR.push(ch); break;
			case ')':
				ch2 = OPTR.top();
				while (ch2 != '(')
				{
					node1 = OPEN.top(); OPEN.pop();
					node2 = OPEN.top(); OPEN.pop();
					tempNode = new fomularNode(int(ch2), true, node2, node1);
					OPEN.push(tempNode);
					OPTR.pop();
					ch2 = OPTR.top();
				}
				OPTR.pop();
				break;
			default:
				ch2 = OPTR.top();
				while (Rank(ch2) >= Rank(ch))
				{
					OPTR.pop();
					node1 = OPEN.top(); OPEN.pop();
					node2 = OPEN.top(); OPEN.pop();
					tempNode = new fomularNode(int(ch2), true, node2, node1);
					OPEN.push(tempNode);
					ch2 = OPTR.top();
				}
				if (ch != '\0')OPTR.push(ch);
				break;
			}//switch
		}//while
		 //cout << ' ' << OPEN.top();
		fomulars.push_back(OPEN.top());
		OPEN.pop();
	}
	return true;
}

bool fomularCore::isSameTree(fomularNode* ro1, fomularNode* ro2)
{
	if (ro1 == NULL && ro2 == NULL)
		return true;
	else if (ro1 == NULL || ro2 == NULL)
		return false;

	if (ro2->value != ro1->value)
		return false;
	else
		return isSameTree(ro1->rchild, ro2->rchild) && isSameTree(ro1->lchild, ro2->lchild);

}

bool fomularCore::isEqualTree(fomularNode* fo1, fomularNode* fo2)
{
	if (fo1 == NULL && fo2 == NULL)
		return true;
	else if (fo1 == NULL || fo2 == NULL)
		return false;

	bool bl1, bl2;
	if (isSameTree(fo1, fo2))//fo2=NULL
		return true;
	else
	{
		bl1 = isEqualTree(fo1->lchild, fo2->lchild) && isEqualTree(fo1->rchild, fo2->rchild);
		bl2 = isEqualTree(fo1->rchild, fo2->lchild) && isEqualTree(fo1->lchild, fo2->rchild);
		return (bl1 || bl2) && (fo1->value == fo2->value);
	}

}

bool fomularCore::toJudgeTree()
{
	int rfomuNum = fomulars.size();

	int regene = 0;

	for (int i = 0; i < rfomuNum; i++)
	{
		okFlag[i] = computeTree(fomulars[i], result[i]);//判断无负
		for (int j = 0; j < i; j++)                   //先判断答案是否一致，一致才有可能是相等表达式
		{
			if (result[i] == result[j])
			{
				if (isEqualTree(fomulars[i], fomulars[j]))
				{
					okFlag[i] = false;
					isEqualTree(fomulars[i], fomulars[j]);
					break;
				}
			}
		}
	}
	return true;
}

void fomularCore::treeTostr(fomularNode* ro, string &pre)
{

	if (ro == NULL)return;
	if (ro->chFlag == false)//只看左边就行，不考虑括号
	{
		pre.append(to_string(ro->value));
		return;
	}


	if (ro->lchild->chFlag == false)
		treeTostr(ro->lchild, pre);
	else if (Rank(ro->value) > Rank(ro->lchild->value))
	{
		pre.push_back('(');
		treeTostr(ro->lchild, pre);
		pre.push_back(')');
	}
	else
		treeTostr(ro->lchild, pre);

	pre.push_back(char(ro->value));

	if (ro->rchild->chFlag == false)
		treeTostr(ro->rchild, pre);
	else if (Rank(ro->value) >= Rank(ro->rchild->value))
	{
		pre.push_back('(');
		treeTostr(ro->rchild, pre);
		pre.push_back(')');
	}
	else
		treeTostr(ro->rchild, pre);

	return;
}

vector<string> fomularCore::fomusToStr(vector<fomularNode*> jFomus)
{
	string tempstr;
	vector<string> outstr;
	for (int i = 0; i < fomuNum; i++)
	{
		treeTostr(jFomus[i], tempstr);
		outstr.push_back(tempstr);
		tempstr.clear();
	}
	return outstr;
}




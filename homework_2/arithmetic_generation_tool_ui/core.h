#ifdef COREDLL_EXPORTS
#define COREDLL_API __declspec(dllexport) 
#else
#define COREDLL_API __declspec(dllimport) 
#endif


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <ctime>
#define MAX_FOMU_NUM 35000

using namespace std;

void ReadXml(string path, int& QuestionNum,
	int & OperandNum, int & NumRange, string & OperatorKind,
	bool & ProperFraction, int &Precise);
//读取当前目录下path对应的xml文件信息，格式按照info.xml
//注意QuestionNum，OperandNum，NumRange必须要求是正整数，而且开头不能是0，如果是010，会报错
//OperatorKind中运算符号顺序：+-*/^()  
//顺序错就会报错
//ProperFraction,Decimal,Power必须是0或者1
//文件中不能存在其他信息，否则会报错 

class fomularNode
{
public:
	int value;
	bool chFlag;//if true，value is ascii
	fomularNode* lchild;
	fomularNode* rchild;
	fomularNode() :value(0),chFlag(false),lchild(NULL),rchild(NULL){}
	fomularNode(int val, bool flag, fomularNode* lch=NULL, fomularNode* rch=NULL)
	{
		value = val;
		chFlag = flag;
		lchild = lch;
		rchild = rch;
	}
};

class fomularCore
{
private:
	vector<fomularNode*> fomulars;
	vector<char> ops = {'+','-','*','/','^','(',')'};//all ops 需要保持最后两个是括号！
	vector<string> finalRes;//最终结果，和Generate返回值一一对应
	int maxopNum = 5;//每个表达式中运算符个数
	int range = 100;//操作数数的上限
	int precise = 2;//输出精度（最大为6）
	int fomuNum;//表达式个数
	int MaxRange = 100000;//运算中出现的最大数
	bool fractionflag = true;//是否进行分数运算
	double result[MAX_FOMU_NUM];//原始字符串运算结果
	bool okFlag[MAX_FOMU_NUM];//判断原始字符串是否符合要求


	bool deletefomu(fomularNode* ro)
	{
		if (ro->lchild != NULL)
			deletefomu(ro->lchild);
		if (ro->rchild != NULL)
			deletefomu(ro->rchild);
		delete ro;
		return true;
	}

	//Calc depending func
	bool isOperate(char ch);
	int Rank(char s);
	double CalcNum(double a, double b, char c);
	void doublepush(stack<double> & st, string exp, int & pos);
	double arthimetic(string & exp);
	int findMultiple(string instr);
	bool withDot(string str);
	int gcd(int a, int b);
	//Calc depending func

	bool isNum(char ch)
	{
		if (ch <= '9'&&ch >= '0')
			return true;
		else
			return false;
	}
	int random(int a, int b)//random int [a,b]
	{
		return (rand() % (b - a + 1)) + a;

	}
	bool computeTree(fomularNode* ro, double &res);

	//原始表达式转后缀并建树
	bool toPostTree(vector<string> & fomus);

	bool isSameTree(fomularNode* ro1, fomularNode* ro2);

	bool isEqualTree(fomularNode* fo1, fomularNode* fo2);


	//根据各种规则判断并处理二叉树
	//采用先随机生成两倍或以上的原始表达式，再从里面挑选符合要求的,由okFlag决定
	bool toJudgeTree();

	vector<string> geneExp(int expNum);//随机生成原始表达式

	void treeTostr(fomularNode* ro, string &pre);

	vector<string> fomusToStr(vector<fomularNode*> jFomus);

public:
	fomularCore(int Num=10)//Num是要生成的表达式个数
	{
		srand((unsigned int)(time(NULL)));

		fomuNum = Num;
	}

	~fomularCore()
	{
		int Num = fomulars.size();
		for (int i = 0; i < Num; i++)
		{
			fomularNode* temp = fomulars[i];
			deletefomu(temp);
		}
	}

	COREDLL_API string Calc(string inputFomu)
	{
		int multi;
		int tp;
		string tpFomu;
		long res;
		multi=findMultiple(inputFomu);

		if (fractionflag&&multi != 1&&!withDot(inputFomu))//有浮点'.'就认为不是分数运算
		{
			tpFomu.append(to_string(multi));
			tpFomu.append("*(");
			tpFomu.append(inputFomu).push_back(')');
			res = int(arthimetic(tpFomu));
			tp = gcd(res, multi);
			tpFomu = to_string(int(res/tp));
			if(multi/tp!=1)
				tpFomu.append("/").append(to_string(multi/tp));
			return tpFomu;
		}
		else
		{
			//这里似乎有概率访问越界
			tpFomu=to_string(arthimetic(inputFomu));
			for (int i = 0; i < 6 - precise; i++)
				tpFomu.pop_back();
			return tpFomu;
		}
	}
	
	COREDLL_API vector<string> Generate()
	{

		vector<string> rawFomu;
		vector<fomularNode*> judgedFomu;
		vector<string> finalFomu;


		rawFomu = geneExp(3*fomuNum);//3是可选参数，保证能选出符合要求个数的表达式

		toPostTree(rawFomu);//建树
		toJudgeTree();//判断是否符合要求

		for (size_t i = 0; i < fomulars.size(); i++)
		{
			if (okFlag[i] == true)
				judgedFomu.push_back(fomulars[i]);//选出合适的树
		}
		

		finalFomu=fomusToStr(judgedFomu);//树转表达式，去除多余括号

		for (size_t i = 0; i < finalFomu.size(); i++)
		{
			//cout << finalFomu[i] << '=';
			//cout << Calc(finalFomu[i]) << endl;//测试输出
			finalRes.push_back(Calc(finalFomu[i]));
		}

		return finalFomu;
	}

	COREDLL_API vector<string> getRes()
	{
		return finalRes;
	}

	COREDLL_API bool settingXml(string path)
	{
		string tpop;
		ReadXml(path, fomuNum, maxopNum, range, tpop, fractionflag, precise);
		for (size_t i = 0; i < ops.size(); i++)
		{
			ops.push_back(tpop[i]);
		}
		return true;
	}

	COREDLL_API bool setting(int foN,int maxopN,int MaxR,string op,bool fraction,int preci)
	{
		fomuNum = foN;
		maxopNum = maxopN;
		range = MaxR;
		ops.clear();
		for (size_t i = 0; i < op.size(); i++)
		{
			ops.push_back(op[i]);
		}
		fractionflag = fraction;
		precise = preci;
		return true;
	}

};
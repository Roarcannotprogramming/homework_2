

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <ctime>
#define MAX_FOMU_NUM 35000

using namespace std;


class fomularNode
{
public:
	int value;
	bool chFlag;//if true��value is ascii
	fomularNode* lchild;
	fomularNode* rchild;
	fomularNode() :value(0), chFlag(false), lchild(NULL), rchild(NULL) {}
	fomularNode(int val, bool flag, fomularNode* lch = NULL, fomularNode* rch = NULL)
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
	vector<char> ops = { '+','-','*','/','^','(',')' };//all ops ��Ҫ����������������ţ�
	vector<string> finalRes;//���ս������Generate����ֵһһ��Ӧ
	int maxopNum = 5;//ÿ�����ʽ�����������
	int range = 100;//��������������
	int precise = 2;//������ȣ����Ϊ6��
	int fomuNum;//���ʽ����
	int MaxRange = 100000;//�����г��ֵ������
	bool fractionflag = true;//�Ƿ���з�������
	double result[MAX_FOMU_NUM];//ԭʼ�ַ���������
	bool okFlag[MAX_FOMU_NUM];//�ж�ԭʼ�ַ����Ƿ����Ҫ��


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

	//ԭʼ���ʽת��׺������
	bool toPostTree(vector<string> & fomus);

	bool isSameTree(fomularNode* ro1, fomularNode* ro2);

	bool isEqualTree(fomularNode* fo1, fomularNode* fo2);


	//���ݸ��ֹ����жϲ����������
	//����������������������ϵ�ԭʼ���ʽ���ٴ�������ѡ����Ҫ���,��okFlag����
	bool toJudgeTree();

	vector<string> geneExp(int expNum);//�������ԭʼ���ʽ

	void treeTostr(fomularNode* ro, string &pre);

	vector<string> fomusToStr(vector<fomularNode*> jFomus);

public:
	fomularCore(int Num = 10)//Num��Ҫ���ɵı��ʽ����
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

	string Calc(string inputFomu)
	{
		int multi;
		int tp;
		string tpFomu;
		long res;
		multi = findMultiple(inputFomu);

		if (fractionflag&&multi != 1 && !withDot(inputFomu))//�и���'.'����Ϊ���Ƿ�������
		{
			tpFomu.append(to_string(multi));
			tpFomu.append("*(");
			tpFomu.append(inputFomu).push_back(')');
			res = int(arthimetic(tpFomu));
			tp = gcd(res, multi);
			tpFomu = to_string(int(res / tp));
			if (multi / tp != 1)
				tpFomu.append("/").append(to_string(multi / tp));
			return tpFomu;
		}
		else
		{
			//�����ƺ��и��ʷ���Խ��
			tpFomu = to_string(arthimetic(inputFomu));
			for (int i = 0; i < 6 - precise; i++)
				tpFomu.pop_back();
			return tpFomu;
		}
	}

	vector<string> Generate()
	{

		vector<string> rawFomu;
		vector<fomularNode*> judgedFomu;
		vector<string> finalFomu;


		rawFomu = geneExp(3 * fomuNum);//3�ǿ�ѡ��������֤��ѡ������Ҫ������ı��ʽ

		toPostTree(rawFomu);//����
		toJudgeTree();//�ж��Ƿ����Ҫ��

		for (size_t i = 0; i < fomulars.size(); i++)
		{
			if (okFlag[i] == true)
				judgedFomu.push_back(fomulars[i]);//ѡ�����ʵ���
		}


		finalFomu = fomusToStr(judgedFomu);//��ת���ʽ��ȥ����������

		for (size_t i = 0; i < finalFomu.size(); i++)
		{
			//cout << finalFomu[i] << '=';
			//cout << Calc(finalFomu[i]) << endl;//�������
			finalRes.push_back(Calc(finalFomu[i]));
		}

		return finalFomu;
	}

	vector<string> getRes()
	{
		return finalRes;
	}


	bool setting(int foN, int maxopN, int MaxR, string op, bool fraction, int preci)
	{
		//��xml��ʽ��setting
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
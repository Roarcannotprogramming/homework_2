#include"package.h"
#include<string.h>
char randsign();

int resu = 0;
FILE* fpResult, *fpSuan;

#define eq ==
#define maxlen 8
#define cuowu -1

map<string, int> mapException;
int num_ques = 50;
int scalemax_op = 10;
int scalemin_op = 0;
int num_op = 8;
int num_float = 2;
bool is_real = 0;
bool is_decimal = 1;
bool is_power = 1;
int result_max = 5;
int result_min = 0;
int is_add = 1;
int is_sub = 1;
int is_mul = 1;
int is_div = 1;

int jiexi(string can)
{
	int a[maxlen], i, result = 0, shi = 1;
	for (i = 0; i < can.length(); i++)
	{
		if (can[i] >= '0'&&can[i] <= '9') a[i] = can[i] - '0';
		else break;
	}
	if (can[i] != ' ') return -1;
	else
	{
		if (can[i + 1] == '\0')
		{
			i--;
			while (i >= 0)
			{
				result += shi * a[i];
				shi *= 10;
				i--;
			}
			return result;
		}
		else return -1;
	}
}

int JudgePrior(char operation)
{
	switch (operation)
	{
	case '+': return 0;
	case '-': return 0;
	case '*': return 1;
	case '/': return 1;
	case '^': return 2;
	default:
		break;
	}
}

bool Judgeoperation(char operation)
{
	if ((operation >= '0') && (operation <= '9'))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void AddBracket(string &exp)
{
	int length = sizeof(exp);
	string real_exp;
	real_exp = "(" + exp + ")";
	exp = real_exp;
}

void ExpTranslate(string Suffix_exp, string result)
{
	stack<MyExp> exp_stk;
	MyExp number_exp;
	int Const_number = 5;
	int flag = 0;
	number_exp.expression = "";
	number_exp.prior = Const_number;
	MyExp oper_first, oper_second, oper_finally;
	int prior;
	int length = size(Suffix_exp);
	for (int i = 0; i < length; i++)
	{
		if (Suffix_exp.at(i) != ' ')
		{
			number_exp.expression += Suffix_exp.at(i);
		}
		else
		{
			if (size(number_exp.expression) == 1)
			{
				if (Judgeoperation(number_exp.expression.at(0)))
				{
					prior = JudgePrior(number_exp.expression.at(0));
					oper_first = exp_stk.top();
					exp_stk.pop();
					oper_second = exp_stk.top();
					exp_stk.pop();
					if (oper_first.prior < prior)
					{
						AddBracket(oper_first.expression);
					}
					if (oper_second.prior < prior)
					{
						AddBracket(oper_second.expression);
					}
					if (number_exp.expression.at(0) == '+' || number_exp.expression.at(0) == '*')
					{
						flag = rand() % 2;
						if (flag == 0)oper_finally.expression = oper_second.expression + " " + number_exp.expression.at(0)+ " " + oper_first.expression;
						else oper_finally.expression = oper_first.expression +" " + number_exp.expression.at(0)+" " + oper_second.expression;
					}
					else oper_finally.expression = oper_second.expression +" " + number_exp.expression.at(0) +" "+ oper_first.expression;
					oper_finally.prior = prior;
					exp_stk.push(oper_finally);
					number_exp.expression = "";
					number_exp.prior = Const_number;
				}
				else
				{
					exp_stk.push(number_exp);
					number_exp.expression = "";
					number_exp.prior = Const_number;
				}
			}
			else
			{
				exp_stk.push(number_exp);
				number_exp.expression = "";
				number_exp.prior = Const_number;
			}
		}
	}
	oper_finally = exp_stk.top();
	exp_stk.pop();
	
	fprintf(fpResult, "%s\n",(char*)result.data());
	fprintf(fpSuan, "%s\n", (char*)oper_finally.expression.data());
	resu++;
}

int Operate(char op, int num1, int &num2)
{
	int result = 1;
	int m;
	int fang = rand() % 5;
	num2 = fang;
	switch (op)
	{
	case '+': return num1 + num2;
	case '-':
		if (num1 == 0) num2 = 0;
		else
		{
			m = (num1 > scalemax_op) ? scalemax_op : num1;
			num2 = (int)scalemin_op + rand() % (m + scalemin_op);
		}
		return num1 - num2;
	case '*': return num1 * num2;
	case '/':
		if (num2 eq 0) return -2;
		else if (num1 % num2 != 0) return -3;
		else return num1 / num2;
	case '^':
		for (int i = 0; i < num2; i++)
		{
			result *= num1;
		}
		return result;
	}
}

string translate(int num)
{
	int j = 1;
	string str = "";
	if (num eq 0)
	{
		str = str + '0';
		return str;
	}
	char tem;
	while (num / j != 0)
	{
		j *= 10;
	}
	j /= 10;
	while (j != 1)
	{
		tem = '0' + num / j;
		str = str + tem;
		num = num % j;
		j /= 10;
	}
	tem = '0' + num;
	str = str + tem;
	return str;
}

int Generate_int()
{
	srand((unsigned)time(NULL));
	map<string, int>::iterator iter;
	string op = "";
	string str1 = "", str2 = "";
	char sign;
	int i = 1, j = 0, temp, num1, num2, flag, result;
	stack<int> num;
	for (j = 0; j < num_ques; j++) {
		op = "";
		for (i = 1; i < num_op; i++)
		{
			sign = randsign();
			num1 = (int)scalemin_op + rand() % (scalemax_op + scalemin_op - 1);
			num2 = (int)scalemin_op + rand() % (scalemax_op + scalemin_op - 1);
			if (i != 1)
			{
				num1 = num.top();
				num.pop();
			}

			flag = Operate(sign, num1, num2);
			while (flag eq - 1 || flag eq - 2 || flag eq - 3 || flag eq - 4)
			{
				num2 = (int)scalemin_op + rand() % (scalemax_op + scalemin_op - 1);
				flag = Operate(sign, num1, num2);
			}
			num.push(flag);

			if (i eq 1)
			{
				str1 = translate(num1);
				str2 = translate(num2);
				op = op + str1 + " " + str2 + " " + sign;
			}
			else
			{
				str2 = translate(num2);
				op = op + " " + str2 + " " + sign;
			}
		}
		result = num.top();
		op = op + ' ';
		if (result > result_max || result < result_min)
		{
			j--;
			continue;
		}

		iter = mapException.find(op);
		if (iter != mapException.end())
		{
			j--;
		}
		else
		{
			mapException.insert(pair<string, int>(op, result));
		}
		num.pop();
		string result_str;
		result_str = translate(result);
		ExpTranslate(op, result_str);
	}
	return 0;
}

double Operate_float(char op, double num1, double num2)
{
	switch (op)
	{
	case '+': return num1 + num2;
	case '-':
		if (num1 - num2 < 0)return -1;
		return num1 - num2;
	case '*': return num1 * num2;
	case '/':
		if (fabs(num2)<1e-6) return -1;
		return num1 / num2;
	}
}

string translate_float(double num)
{
	int temp;
	int j = pow(10, num_float);
	int int_part = 0;
	string int_str, float_str;
	int_part = (int)num;
	num = num * pow(10, num_float);
	temp = (int)(num + 0.5);
	int_part = temp / pow(10, num_float);
	int_str = translate(int_part);
	float_str = "";
	for (int i = 1; i <= num_float; i++)
	{
		j = j / 10;
		float_str += translate((temp / j) % 10);
	}
	return int_str + "." + float_str;
}
float Fix_precious(double num)
{
	int int_part = 0;
	double fix = num;
	int temp;
	fix = fix * pow(10, num_float);
	temp = (int)(fix + 0.5);
	fix = temp / pow(10, num_float);
	if (fabs((fix - num))<1e-6)
	{
		return num;
	}
	else
	{
		return fix;
	}
}
int Generate_float()
{
	srand((unsigned)time(NULL));
	map<string, int>::iterator iter;
	string op = "";
	string str1 = "", str2 = "";
	char sign;
	int i = 1, j = 0, temp;
	double num1, num2;
	double result, flag;
	float precious = (5 / (pow(10, num_float + 1)));
	stack<float> num;

	for (j = 0; j < num_ques; j++) {
		op = "";
		for (i = 1; i < num_op; i++)
		{
			sign = randsign();

			int jin = 1;
			for (size_t jingdu = 0; jingdu < num_float; jingdu++)
			{
				jin *= 10;
			}

			num1 = (int)scalemin_op + rand() % (scalemax_op + scalemin_op - 1) + ((double)(rand() % (jin)) / jin);
			num2 = (int)scalemin_op + rand() % (scalemax_op + scalemin_op - 1) + ((double)(rand() % (jin)) / jin);
			if (i != 1)
			{
				num1 = num.top();
				num.pop();
			}

			int fang;
			if (sign eq '^')
			{
				flag = 1;
				fang = rand() % 3;
				for (int k = 0; k < fang; k++)
				{
					flag = Operate_float('*', Fix_precious(flag), Fix_precious(num1));
				}
			}
			else
				if (i == 1)
				{
					flag = Operate_float(sign, Fix_precious(num1), Fix_precious(num2));
				}
				else
				{
					flag = Operate_float(sign, num1, Fix_precious(num2));
				}
			while (fabs(flag + 1)<1e-5 || fabs(flag + 2)<1e-5)
			{
				num2 = (int)scalemin_op + rand() % (scalemax_op + scalemin_op - 1) + ((double)(rand() % (jin)) / jin);
				if (i == 1)
				{
					flag = Operate_float(sign, Fix_precious(num1), Fix_precious(num2));
				}
				else
				{
					flag = Operate_float(sign, num1, Fix_precious(num2));
				}
			}
			num.push(flag);

			if (i eq 1)
			{
				str1 = translate_float(num1);
				if (sign != '^') str2 = translate_float(num2);
				else str2 = translate(fang);
				op = op + str1 + " " + str2 + " " + sign;
			}
			else
			{
				if (sign != '^') str2 = translate_float(num2);
				else str2 = translate(fang);
				op = op + " " + str2 + " " + sign;
			}
		}
		op = op + ' ';
		result = num.top();
		if (result - result_max > 0 || result - result_min < 0)
		{
			j--;
			continue;
		}

		iter = mapException.find(op);
		if (iter != mapException.end())
		{
			j--;
		}
		else
		{
			mapException.insert(pair<string, int>(op, result));
		}
		num.pop();

		string result_str;
		result_str = translate_float(result);
		ExpTranslate(op, result_str);
	}
	return 0;
}

int GreatCommon(int fenzi, int fenmu)
{
	int n;
	do
	{
		n = fenzi % fenmu;
		fenzi = fenmu;
		fenmu = n;

	} while (n != 0);
	return fenzi;
}

void Simplify(fenshu &sample)
{
	int max;
	max = GreatCommon(sample.fenzi, sample.fenmu);
	sample.fenmu /= max;
	sample.fenzi /= max;
}

fenshu Add(fenshu a1, fenshu a2)
{
	fenshu a3;
	a3.fenmu = a1.fenmu*a2.fenmu;
	a3.fenzi = a1.fenzi*a2.fenmu + a1.fenmu*a2.fenzi;
	return a3;
}

fenshu Sub(fenshu a1, fenshu a2)
{
	fenshu a3;
	a3.fenmu = a1.fenmu*a2.fenmu;
	a3.fenzi = a1.fenzi*a2.fenmu - a1.fenmu*a2.fenzi;
	return a3;
}

fenshu chen(fenshu a1, fenshu a2)
{
	fenshu a3;
	a3.fenmu = a1.fenmu*a2.fenmu;
	a3.fenzi = a1.fenzi*a2.fenzi;
	return a3;
}

fenshu chu(fenshu a1, fenshu a2)
{
	fenshu a3;
	a3.fenmu = a1.fenmu*a2.fenzi;
	a3.fenzi = a1.fenzi*a2.fenmu;
	return a3;
}

fenshu Operate_fenshu(char op, fenshu num1, fenshu &num2)
{
	fenshu temp;
	fenshu cuowu1;
	cuowu1.fenzi = 1;
	switch (op)
	{
	case '+': return Add(num1, num2);
	case '-':
		if (num1.fenzi == 0)
		{
			num2.fenzi = 0;
			temp = Sub(num1, num2);
			return temp;
		}
		else
		{
			//num2.fenzi = (int)scalemin_op + rand() % (num1.fenzi + scalemin_op);
			//num2.fenmu = num1.fenmu;
			temp = Sub(num1, num2);
			if (temp.fenzi < 0) {
				cuowu1.fenmu = 0;
				return cuowu1;
			}
			return temp;
		}
	case '*': return chen(num1, num2);
	case '/':
		if (num2.fenzi eq 0) {
			cuowu1.fenmu = 0;
			return cuowu1;
		}
		return chu(num1, num2);
	}
}

string translate_fenshu(fenshu sample)
{
	string str = "";
	if (sample.fenzi eq 0)
	{
		str = "0";
		return str;
	}
	if (sample.fenmu == 1)
	{
		str = translate(sample.fenzi);
		return str;
	}
	else
	{
		if (sample.fenzi > sample.fenmu)
		{
			int k = sample.fenzi / sample.fenmu;
			int j = sample.fenzi % sample.fenmu;
			str += translate(k) + '`' + translate(j) + '/' + translate(sample.fenmu);
		}
		else
		{
			str += translate(sample.fenzi) + '/' + translate(sample.fenmu);
		}
	}
	//str += '';
	return str;
}

int Generate_fenshu()
{
	srand((unsigned)time(NULL));
	map<string, int>::iterator iter;
	string op = "";
	string str1 = "", str2 = "";
	char sign;
	int i = 1, j = 0, temp;
	fenshu num1, num2;
	fenshu result, flag;
	int jj = 0;
	stack<fenshu> num;

	for (j = 0; j < num_ques; j++) {
		op = "";
		for (i = 1; i < num_op; i++)
		{
			sign = randsign();

			num1.fenzi = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);
			num1.fenmu = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);

			while (num1.fenmu == 0) num1.fenmu = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);
			num2.fenmu = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);
			while (num2.fenmu == 0) num2.fenmu = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);
			num2.fenzi = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);

			if (i != 1)
			{
				num1 = num.top();
				num.pop();
			}

			int fang;
			if (sign eq '^')
			{
				flag.fenmu = 1;
				flag.fenzi = 1;
				fang = rand() % 4;
				if (num1.fenzi < 10 && num1.fenzi < 10)
				{
					for (int k = 0; k < fang; k++)
					{
						flag = chen(flag, num1);
					}
				}
				else
				{
					j--;
					jj = 1;
					break;
				}
			}
			else flag = Operate_fenshu(sign, num1, num2);

			while (flag.fenmu == 0)
			{
				num2.fenmu = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);
				while (num2.fenmu == 0)num2.fenmu = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);
				num2.fenzi = (int)scalemin_op + rand() % (scalemax_op + scalemin_op);

				flag = Operate_fenshu(sign, num1, num2);
			}
			Simplify(flag);

			num.push(flag);

			if (i eq 1)
			{
				Simplify(num1);
				Simplify(num2);
				str1 = translate_fenshu(num1);
				if (sign != '^') str2 = translate_fenshu(num2);
				else str2 = translate(fang);
				op = op + str1 + " " + str2 + " " + sign;
			}
			else
			{
				Simplify(num2);
				if (sign != '^') str2 = translate_fenshu(num2);
				else str2 = translate(fang);
				op = op + " " + str2 + " " + sign;
			}
		}
		if (jj == 1)
		{
			jj = 0;
			continue;
		}
		op = op + ' ';

		result = num.top();
		if (result.fenmu > result_max || result.fenmu < result_min)
		{
			j--;
			continue;
		}
		if (result.fenzi > result_max || result.fenzi < result_min)
		{
			j--;
			continue;
		}
		iter = mapException.find(op);
		if (iter != mapException.end())
		{
			j--;
		}
		else
		{
			mapException.insert(pair<string, int>(op, 1));
		}
		num.pop();


		string result_str;
		result_str = translate_fenshu(result);
		ExpTranslate(op, result_str);
	}
	return 0;
}

char randsign()
{
	int temp;
	char sign;
	temp = rand() % (7);
	switch (temp)
	{
	case 0: if (is_add) { sign = '+'; break; }
	case 1: if (is_sub) { sign = '-'; break; }
	case 2: if (is_div) { sign = '/'; break; }
	case 3: if (is_mul) { sign = '*'; break; }
	case 4: if (is_add) { sign = '+'; break; }
	case 5: if (is_sub) { sign = '-'; break; }
	case 6: if (is_power) { sign = '^'; break; }
	default:
		if (is_add) { sign = '+'; break; }
		if (is_sub) { sign = '-'; break; }
		if (is_mul) { sign = '*'; break; }
		if (is_div) { sign = '/'; break; }
	}
	return sign;
}

int Produce(canshu sample)
{
	fopen_s(&fpResult,"result.txt", "w");
	fopen_s(&fpSuan,"suanshi.txt", "w");
	
	if (sample.num_ques >= 10000|| sample.num_ques < 0) return cuowu;
	else num_ques = sample.num_ques;

	if (sample.is_power == 0 || sample.is_power == 1) is_power = sample.is_power;
	else return cuowu;

	if (sample.is_add == 0 || sample.is_add == 1) is_add = sample.is_add;
	else return cuowu;

	if (sample.is_sub == 0 || sample.is_sub == 1) is_sub = sample.is_sub;
	else return cuowu;

	if (sample.is_div == 0 || sample.is_div == 1) is_div = sample.is_div;
	else return cuowu;

	if (sample.is_mul == 0 || sample.is_mul == 1) is_mul = sample.is_mul;
	else return cuowu;

	if (sample.is_mul == 0 && sample.is_add == 0 && sample.is_sub == 0 && sample.is_div == 0 && sample.is_power == 0)
		return cuowu;

	if (sample.is_real == 0 || sample.is_real == 1) is_real = sample.is_real;
	else return cuowu;

	if (sample.is_decimal == 0 || sample.is_decimal == 1) is_decimal = sample.is_decimal;
	else return cuowu;

	
	if (is_power == 1 || is_mul == 1) { if (sample.scalemax_op >= 20) return cuowu; else scalemax_op = sample.scalemax_op; }
	else { if (sample.scalemax_op >= 500) return cuowu; else scalemax_op = sample.scalemax_op; }
	

	if (sample.num_op >= 10 || sample.num_op < 0) return cuowu;
	else num_op = sample.num_op;

	if (sample.num_float >= 10 || sample.num_float < 0) return cuowu;
	else num_float = sample.num_float;

	if (sample.result_max >= 1000000 || sample.result_max < 0) return cuowu;
	else result_max = sample.result_max;


	if (is_real == 0 && is_decimal == 0) Generate_int();
	else if (is_real == 0 && is_decimal == 1)Generate_float();
	else if (is_real == 1 && is_decimal == 0)Generate_fenshu();
	else if (is_real == 1 && is_decimal == 1)Generate_float();
	resu = 0;
	fclose(fpSuan);
	fclose(fpResult);

	return 0;
}
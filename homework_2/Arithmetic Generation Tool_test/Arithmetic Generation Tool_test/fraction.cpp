#include"head.h"
int gcd(int a, int b)//求a,b的最大公约数
{
	if (b == 0) return a;
	else return gcd(b, a%b);
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
Fraction fraction(int up, int down)//生成分数
{
	Fraction result;
	result.up = up;
	result.down = down;
	strstream ss, kk;
	ss << result.up; ss >> result.high;
	kk << result.down; kk >> result.low;
	return result;
}
Fraction fra(int d,int u)//生成真分数
{
	Fraction result;
	int temp1 = suiji(d, u);//调用function函数随机生成两个随机整数
	int temp2 = suiji(d, u);
	result.up = min(temp1, temp2);
	result.down = max(temp1, temp2);
	strstream s1, s2;
	s1 << result.up; s1 >> result.high;
	s2 << result.down; s2 >> result.low;
	return result;
}
Fraction reduction(Fraction result)//分数的化简
{
	if (result.down < 0)
	{
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0)
	{
		result.down = 1;
	}
	else
	{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	strstream s3, s4;
	s3 << result.up; s3 >> result.high;
	s4 << result.down; s4 >> result.low;
	return result;
}
Fraction add(Fraction f1, Fraction f2)//分数的加法
{
	Fraction result;
	result.up = f1.up*f2.down + f1.down * f2.up;
	result.down = f1.down*f2.down;
	return reduction(result);
}
Fraction minus1(Fraction f1, Fraction f2)//分数的减法
{
	Fraction result;
	result.up = f1.up*f2.down - f1.down*f2.up;
	result.down = f1.down*f2.down;
	return reduction(result);
}
Fraction multi(Fraction f1, Fraction f2)//分数的乘法
{
	Fraction result;
	result.up = f1.up*f2.up;
	result.down = f1.down*f2.down;
	return reduction(result);
}
Fraction divide(Fraction f1, Fraction f2)//分数的除法
{
	Fraction result;
	result.up = f1.up*f2.down;
	result.down = f1.down*f2.up;
	return reduction(result);
}
void ShowResult(Fraction f)//输出分数
{
	f = reduction(f);
	if (f.down == 1) cout << f.up;
	else cout << f.up << "\\" << f.down;
}
string FraToString(Fraction f)//将分数转换为string类型
{
	string result;
	if (f.down == 1) result = f.high;
	else result = f.high + "\\" + f.low;
	return result;
}

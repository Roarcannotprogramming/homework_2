// ConsoleApplication6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"
#include "package.h"
using namespace std;
#pragma comment(lib,"Project3.lib")
int main()
{
	canshu sample;
	int num = 10;
	sample.is_add = 1;
	sample.is_sub = 0;
	sample.is_mul = 0;
	sample.is_div = 0;
	sample.is_power = 0;

	sample.is_real = 0;
	sample.is_decimal = 0;

	sample.num_float = 3;
	sample.num_op = 5;
	sample.scalemax_op = 100;
	sample.result_max = 1000;
	sample.num_ques = 100;
	
	num = Produce(sample);
	printf("%d", num);
	

    return 0;
}


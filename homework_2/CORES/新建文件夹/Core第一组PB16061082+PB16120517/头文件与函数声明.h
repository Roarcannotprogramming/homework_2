
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include<map>
#include<math.h>

using namespace std;
typedef struct ExpDetail {
	string expression;
	int prior;
}MyExp;

typedef struct fenshu {
	int fenzi;
	int fenmu;
}fenshu;

typedef struct fanhui {
	string express;
	string result;
}fanhui;

typedef struct canshu {
	int num_ques;
	int scalemax_op;
	int num_op;
	int num_float;
	int is_real;
	int is_decimal;
	int is_power;
	int is_add;
	int is_sub;
	int is_mul;
	int is_div;
	int result_max;
}canshu;
extern "C++" _declspec(dllexport) int Produce(canshu sample);


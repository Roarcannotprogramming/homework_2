#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
/*
class A {
public:
	int sizx;
	A() {
		this->pan = 1;
	}
	A(int x) :pan(x) {
		this->pan = x;
		this->sizx = x;
	}
	~A() {
		;
	}
private:
	int pan;
	int pl;
	int pll;
};*/
/*
int main() {
	srand((unsigned)time(NULL));
	for(int ii=0;ii<10;ii++)
	cout << rand() << endl;
	system("pause");
}*/
/*
int main() {
	A *pA = new A[10];
	cout << sizeof(pA) << endl;
	cout << pA->sizx<<endl;
	delete[] pA;
	system("pause");
}*/
//char *Formula = new char[32]();
class Node {
public:
	char oper_or_num;
	bool is_num;
	int value;
	Node() {
		oper_or_num = '\0';
		is_num = false;
		value = -23333;
	}
	Node(char op_num, bool is_n) {
		oper_or_num = op_num;
		is_num = is_n;
		if (is_num) {
			value = oper_or_num - '0';
		}
		else
			value = -23333;
	}
	void operator=(const Node &another) {
		oper_or_num = another.oper_or_num;
		is_num = another.is_num;
		value = another.value;
	}
};

class Formula {
	/*���ڴ�ű��ʽ*/
public:
	Formula() {
		/*Ĭ�Ϲ��캯��*/
		size = 32;
		Formula_vector = new Node[size]();
	}
	Formula(unsigned int sz) {
		/*���캯��*/
		size = sz;
		Formula_vector = new Node[size]();
	}
	Formula(const Formula &another) {
		/*�������캯��*/
		Formula_vector = new Node[another.size];
		for (int ii = 0; ii < another.size; ii++) {
			this->Formula_vector[ii] = another.Formula_vector[ii];
		}
	}
	virtual ~Formula() {
		/*��������*/
		delete[] Formula_vector;
	}

	void init() {
		/*����һ���Ϸ��ı��ʽ*/
		init_num();
		init_oper();
	}

	void init_num() {
		/*�����ֳ�ʼ��������Ϊ�±�Ϊ[size/2, size-1]��Ԫ��*/
		srand((unsigned)time(NULL));
		for (int ii = size / 2; ii < size; ii++) {
			Formula_vector[ii].is_num = true;
			Formula_vector[ii].oper_or_num = rand() % 100;
			Formula_vector[ii].value = Formula_vector[ii].oper_or_num - '0';
		}
	}

	void init_oper() {
		/*���ַ���ʼ�����ַ��±�Ϊ[1, (size/2)-1]*/
		for (int ii = size/2-1; ii > 0; ii--) {
			Formula_vector[ii].is_num = false;
			switch (rand()%4) {
			case 0: Formula_vector[ii].oper_or_num = '+';
					Formula_vector[ii].value = Formula_vector[2 * ii].value + Formula_vector[2 * ii + 1].value;
					break;
			case 1: Formula_vector[ii].oper_or_num = '-';
					Formula_vector[ii].value = Formula_vector[2 * ii].value - Formula_vector[2 * ii + 1].value;
					break;
			case 2: Formula_vector[ii].oper_or_num = '*';
					Formula_vector[ii].value = Formula_vector[2 * ii].value * Formula_vector[2 * ii + 1].value;
					break;
			case 3: Formula_vector[ii].oper_or_num = '/';
					Formula_vector[ii].value = Formula_vector[2 * ii].value / Formula_vector[2 * ii + 1].value;
					break;
			}
		}
	}

	void travel(int ii) {
		/*��������õ����ʽ*/
		
	}

	void print() {
		/*������ʽ*/

	}



	unsigned int get_size() {
		/*��ȡ�����С��һ��sizeΪ2�Ĵη���*/
		return size;
	}
private:
	Node *Formula_vector;
	unsigned int size;
};

int main() {
	Formula fo_1;
	cout << fo_1.get_size() << endl;
	system("pause");
}

/*
int main() {
	for (int ii = 0; ii < 32; ii++)
		cout << Formula[ii] << endl;
	system("pause");
}*/
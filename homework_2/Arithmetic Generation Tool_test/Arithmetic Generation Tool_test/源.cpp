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
	/*用于存放表达式*/
public:
	Formula() {
		/*默认构造函数*/
		size = 32;
		Formula_vector = new Node[size]();
	}
	Formula(unsigned int sz) {
		/*构造函数*/
		size = sz;
		Formula_vector = new Node[size]();
	}
	Formula(const Formula &another) {
		/*拷贝构造函数*/
		Formula_vector = new Node[another.size];
		for (int ii = 0; ii < another.size; ii++) {
			this->Formula_vector[ii] = another.Formula_vector[ii];
		}
	}
	virtual ~Formula() {
		/*析构函数*/
		delete[] Formula_vector;
	}

	void init() {
		/*生成一个合法的表达式*/
		init_num();
		init_oper();
	}

	void init_num() {
		/*把数字初始化，数字为下标为[size/2, size-1]的元素*/
		srand((unsigned)time(NULL));
		for (int ii = size / 2; ii < size; ii++) {
			Formula_vector[ii].is_num = true;
			Formula_vector[ii].oper_or_num = rand() % 100;
			Formula_vector[ii].value = Formula_vector[ii].oper_or_num - '0';
		}
	}

	void init_oper() {
		/*把字符初始化，字符下标为[1, (size/2)-1]*/
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
		/*中序遍历得到表达式*/
		
	}

	void print() {
		/*输出表达式*/

	}



	unsigned int get_size() {
		/*获取数组大小，一般size为2的次方数*/
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
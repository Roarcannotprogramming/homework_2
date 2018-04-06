#include"head.h"
int main()
{
	cout << "请输入题目数(1~100)：";
	int times, down, up, flag1, flag2, flag3, flag4;
	cin >> times;//times至题目数
	cout << "请输入数值绝对值范围:";
	cin >> down >> up;//[down,up]为运算数范围
	cout << "是否允许乘除发参与运算（y/n）:";
	char yn1;
	cin >> yn1;
	yn1 == 'y' || yn1 == 'Y' ? flag1 = 1 : flag1 = 0;
	cout << "是否允许括号（[]）参与运算（y/n）:";
	char yn2;
	cin >> yn2;
	yn2 == 'y' || yn2 == 'Y' ? flag2 = 1 : flag2 = 0;//flag2判断是否允许括号参与运算
	cout << "是否允许真分数参与运算（y/n）：";
	char yn3;
	cin >> yn3;
	yn3 == 'y' || yn3 == 'Y' ? flag3 = 1 : flag3 = 0;//flag3判断是否允许真分数参与运算
	cout << "**********************************************************************************" << endl;
	yunsuan(times, down, up, flag1, flag2, flag3);
	system("pause");
	return 0;
}
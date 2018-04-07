#include <iostream>  
#include <fstream>  
using namespace std;

int main()
{
	ofstream mcfile; //创建个对象  
	mcfile.open("./mingci.txt",ios::app); //创建文件  
	mcfile << u8"欢迎来到我的博客：http://hi.baidu.com/tomorrow93"<<endl;  //写入内容  
	mcfile.close(); //关闭  
	return 0;
}
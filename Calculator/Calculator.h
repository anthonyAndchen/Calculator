#pragma once
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;
//计算器类
class Calculator
{
public:
	Calculator();
	void getFormat();           // 表达式格式化
	int getPrior(char c);       // 获取运算符优先级
	void getPostfix();          // 后缀表达式转换
	void calResult();           // 计算结果
	void calculate();			// 计算方法
	double getResult();         // 获取结果

	string opera;               // 运算符号
	string infix;               // 表达式暂存

private:
	vector<string> postfix;      // 后缀表达式
	stack<char> opStack;         // 符号栈
	stack<double> figStack;      // 数字栈
	string stdInfix;             // 格式化标准表达式
	double result;               // 最终结果
};


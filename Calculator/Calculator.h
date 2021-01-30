#pragma once
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;
//��������
class Calculator
{
public:
	Calculator();
	void getFormat();           // ���ʽ��ʽ��
	int getPrior(char c);       // ��ȡ��������ȼ�
	void getPostfix();          // ��׺���ʽת��
	void calResult();           // ������
	void calculate();			// ���㷽��
	double getResult();         // ��ȡ���

	string opera;               // �������
	string infix;               // ���ʽ�ݴ�

private:
	vector<string> postfix;      // ��׺���ʽ
	stack<char> opStack;         // ����ջ
	stack<double> figStack;      // ����ջ
	string stdInfix;             // ��ʽ����׼���ʽ
	double result;               // ���ս��
};


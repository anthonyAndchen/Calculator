#pragma once
#include <string>
#include <vector>
#include <stack>

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


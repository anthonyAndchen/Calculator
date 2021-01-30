#include "Calculator.h"

//算数运算符优先级
enum PRIO_LV {
	PRIO_LV0 = 0,
	PRIO_LV1 = 1,
	PRIO_LV2 = 2,
	PRIO_LV3 = 3,
	PRIO_LV4 = 4,	
};

//获取算术符号优先级
int Calculator::getPrior(char c)
{
	if (c == '+' || c == '-') {
		return PRIO_LV1;
	}
	else if (c == '*' || c == '/') {
		return PRIO_LV2;
	}
	else if (c == '%' || c == '^') {
		return PRIO_LV3;
	}
	else {
		return PRIO_LV0;        //非法符号
	}
}

//表达式标准格式化
void Calculator::getFormat()
{
	stdInfix = infix;
	for (size_t i = 0; i < stdInfix.size(); i++){
		if (stdInfix[i] == '-' || stdInfix[i] == '+'){      //-x转换为0-x，+x转化为0+x
			if (i == 0) {
				stdInfix.insert(0, 1, '0');
			}
			else if (stdInfix[i - 1] == '(') {
				stdInfix.insert(i, 1, '0');
			}
		}
	}
}

//后缀表达式转换
void Calculator::getPostfix()
{
	string tmp;
	for (size_t i = 0; i < stdInfix.size(); i++) {
		tmp == "";
		switch (stdInfix[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			if (opStack.empty() || opStack.top() == '(') {
				opStack.push(stdInfix[i]);
			}
			else {
				while (!opStack.empty() && (getPrior(opStack.top()) >= getPrior(stdInfix[i]))) {
					tmp += opStack.top();
					postfix.push_back(tmp);
					opStack.pop();
					tmp = "";
				}
				opStack.push(stdInfix[i]);
			}
			break;
		case '(':
			opStack.push(stdInfix[i]);
			break;
		case ')':
			while (!opStack.empty() && opStack.top() != '(') {
				tmp += opStack.top();
				postfix.push_back(tmp);
				opStack.pop();
				tmp = "";
			}
			if (!opStack.empty() && opStack.top() == '(') {
				opStack.pop();    //左括号丢弃出栈
			}
			break;
		default:
			if ((stdInfix[i] >= '0') && (stdInfix[i] <= '9')) {
				tmp += stdInfix[i];
				//小数处理
				while (i + 1 < stdInfix.length() && ((stdInfix[i + 1] >= '0' && stdInfix[i + 1] <= '9') || stdInfix[i + 1] == '.')) {
					tmp += stdInfix[i + 1];   //是连续的数字，追加
					i++;
				}
				if (tmp[tmp.length() - 1] == '.') {
					tmp += '0';     //将 x. 作 x.0
				}
				postfix.push_back(tmp);
			}
			break;
		}//end switch
	}//end for
	while (!opStack.empty()) {     //将栈中剩余符号加入后缀表达式
		tmp = "";
		tmp += opStack.top();
		postfix.push_back(tmp);
		opStack.pop();
	}
}
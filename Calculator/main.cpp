#include <iostream>
#include "Calculator.h"
using namespace std;

int main()
{
	Calculator cal;
	cout << cal.opera << endl;
	cout << "----------------------------" << endl;
	while (true) {
		getline(cin, cal.infix);
		cal.calculate();
		cout << cal.getResult() << endl;
	}
	return 0;
}
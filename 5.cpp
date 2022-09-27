/*
5. 계산기 기능의 Calculator 클래스를 작성하여 다음의 프로그램이 동작 되도록 완성 하시오. 
기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈, 나눗셈이며, 연산을 할 때마다 어떠한 연산을 몇 번 수행했는지 기록되어야 한다. 
멤버변수는 private, 멤버함수는 public으로 선언한다. 

int main()
{
	Calculator cal;

	cal.Init();

	cout << "3.3 + 2.8 = " << cal.Add(3.3, 2.8) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.1 - 1.1 = " << cal.Min(2.1, 1.1) << endl;
	cout << "2.1 * 1.1 = " << cal.Mul(2.1, 1.1) << endl;

	cal.ShowCount();

	return 0;
}

*/
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

enum {PLUS, MINUS, TIMES, DEVIDE};

class Calculator
{
private:
    int cnt;
    int* pcnt;
public:
    Calculator();
    virtual ~Calculator();
    void Init();
    double Add(double a, double b);
    double Div(double a, double b);
    double Min(double a, double b);
    double Mul(double a, double b);
    
    void ShowCount();
};

Calculator::Calculator()
{
    pcnt = &cnt;
    *pcnt = 0;
}
Calculator::~Calculator(){}
void Calculator::Init()
{
    *pcnt = 0;
}

double Calculator::Add(double a, double b)
{
    *pcnt += 1;
    return a + b;
}

double Calculator::Div(double a, double b)
{
    *pcnt += 1;
    return a / b;
}

double Calculator::Min(double a, double b)
{
    *pcnt += 1;
    return a - b;

}

double Calculator::Mul(double a, double b)
{
    *pcnt += 1;

    return  a * b;
}

void Calculator::ShowCount()
{
    cout << "총 계산횟수 : " << cnt << endl;
}

int main()
{
	Calculator cal;

	cal.Init();

	cout << "3.3 + 2.8 = " << cal.Add(3.3, 2.8) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.1 - 1.1 = " << cal.Min(2.1, 1.1) << endl;
	cout << "2.1 * 1.1 = " << cal.Mul(2.1, 1.1) << endl;

	cal.ShowCount();

    return 0;
}
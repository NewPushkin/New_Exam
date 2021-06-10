#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <climits>

using namespace std;

int num()
{
	int res = 0;
	for (;;)
	{
		char c = cin.get();
		if (c >= '0' && c <= '9') res = res * 10 + c - '0';
		else
		{
			cin.putback(c);
			return res;
		}
	}
}

int expr();
int sk()
{
	char c = cin.get();
	if (c == '(')
	{
		int x = expr();
		cin.get();
		return x;
	}
	else
	{
		cin.putback(c);
		return num();
	}
}

int oper()
{
	int n = sk();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '*':
			n *= sk();
			break;
		case '/':
			n /= sk();
			break;
		default:
			cin.putback(c);
			return n;
		}
	}
}

int expr()
{
	int n = oper();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '+':
			n += oper();
			break;
		case '-':
			n -= oper();
			break;
		default:
			cin.putback(c);
			return n;
		}
	}

}
int main()
{
	int res = expr();
	cout << res;
}
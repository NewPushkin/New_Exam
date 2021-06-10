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

int main()
{
	int a, b, count = 0;
	cin >> a >> b;
	if (a == 0 && b == 0) cout << 0;
	else if (a == 0 && b > 0)
	{
		a = 1;
		for (a; a <= b; a++)
		{
			int c = a, simp = 0;
			while (c % 2 == 0) c /= 2;
			int asq = sqrt(sqrt(c));
			if (pow(asq, 4) == c)
			{
				for (int i = 3; i <= asq; i++)
				{
					if (asq % i == 0) simp++;
					if (simp > 1) break;
				}
				if (simp == 1)
				{
					cout << a << endl;
					count++;
				}
			}
		}
		if (count == 0) cout << 0;
	}
	else
	{
		for (a; a <= b; a++)
		{
			int c = a, simp = 0;
			while (c % 2 == 0) c /= 2;
			int asq = sqrt(sqrt(c));
			if (pow(asq, 4) == c)
			{
				for (int i = 3; i <= asq; i++)
				{
					if (asq % i == 0) simp++;
					if (simp > 1) break;
				}
				if (simp == 1)
				{
					cout << a << endl;
					count++;
				}
			}
		}
		if (count == 0) cout << 0;
	}
}

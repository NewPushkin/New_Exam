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

int A[100];

void sum(int a, int b, int c)
{
	if (!c)
	{
		
		for (int i = a - 1; i >= 1; i--) cout << A[i] << " ";
		cout << A[0] << endl;
	//	cout << endl;
	}
	else
	{
		for (int i = 1; i <= min(b, c); i++)
		{
			A[a] = i;
			sum(a + 1, i, c - i);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	sum(0, n, n);
}

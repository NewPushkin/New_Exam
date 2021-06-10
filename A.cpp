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

int two(int a)
{
	if (a == 0) return 0;
	else {
		vector <int> A;
		a = abs(a);
		while (a > 0)
		{
			A.push_back(a % 2);
			a /= 2;
		}
		return A[0];
	}
}

int sum(int a)
{
	if (a == 0) return 1;
	else {
		vector <int> A;
		int zero = 0, count_0 = 0;
		a = abs(a);
		while (a > 0)
		{
			A.push_back(a % 2);
			a /= 2;
			zero++;
		}
		for (int i = 0; i < zero; i++) if (A[i] == 0) count_0++;
		return count_0;
	}
}
int main()
{
	int a, b, count = 0, max = INT_MIN, imax;
	vector <int> B;
	cin >> a >> b;
	for (a; a <= b; a++) if (two(a) == 1 && sum(a) == 5 && a % 33 == 0)
	{
		B.push_back(a);
		count++;
	}
	if (count != 0)
	{
		for (int i = 0; i < B.size(); i++) if (B[i] >= max)
		{
			max = B[i];
			imax = i;
		}
		cout << count << " " << max;
	}
	else cout << 0 << " " << 0;
}
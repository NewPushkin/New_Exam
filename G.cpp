#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <climits>

using namespace std;

int** w;
int** h;
int n;
int a, b;

void print(int u, int v)
{
	if (h[u][v] == 0)
	{
		return;
	}
	else
	{
		print(u, h[u][v] - 1);
		cout << h[u][v] << " ";
	}
}
void Floid()
{
	int tmp;
	cin >> n;
	w = new int* [n];
	h = new int* [n];
	for (int i = 0; i < n; i++)
	{
		w[i] = new int[n];
		h[i] = new int[n];
		for (int j = 0; i < n; j++) {
			cin >> w[i][j];
			h[i][j] = 0;
		}
	}
	cin >> a >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; i < n; j++) {
			if (i != j) {
				if (w[i][j] == 0) w[i][j] = 1e8;
				else h[i][j] = i + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; i < n; j++)
			for (int k = 0; k < n; k++)
				if (w[i][k] > w[i][j] + w[j][k])
				{
					w[i][k] = w[i][j] + w[j][k];
					h[i][k] = j + 1;
				}
	cout << w[a - 1][b - 1] << endl;
	print(a - 1, b - 1);
	cout << b;
	return;
}
int main()
{
	Floid();
	return 0;
}
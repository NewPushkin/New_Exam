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

typedef struct Tpoint
{
	int x, y;
};

Tpoint Point(int x, int y)
{
	Tpoint P;
	P.x = x;
	P.y = y;
	return P;
}

int main()
{
	ifstream fin;
	ofstream  fout;
	fin.open("input.txt");
	fout.open("output.txt");
	queue<Tpoint> Q;
	Tpoint pt;
	int n, m, colour, new_colour, x0, y0;

	fin >> n >> m;
	fin >> y0 >> x0;
	fin >> new_colour;
	int** A = new int* [n];
	for (int i = 0; i < n; i++) A[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> A[i][j];
		}
	}

	colour = A[x0][y0];
	Q.push(Point(x0, y0));
	if (colour != new_colour)
	{
		while (!Q.empty())
		{
			pt = Q.front();
			Q.pop();
			if (A[pt.x][pt.y] == colour)
			{
				A[pt.x][pt.y] = new_colour;
				if (pt.x > 0) Q.push(Point(pt.x - 1, pt.y));
				if (pt.y > 0) Q.push(Point(pt.x, pt.y - 1));
				if (pt.x < n - 1) Q.push(Point(pt.x + 1, pt.y));
				if (pt.y < m - 1) Q.push(Point(pt.x, pt.y + 1));
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				fout << A[i][j] << " ";
			}
			fout << endl;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				fout << A[i][j] << " ";
			}
			fout << endl;
		}
	}
}
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
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	string s, s1;
	int imax = 0, count = 1;
	getline(fin, s);
	s1 = s[0];
	string s2 = s1;
	for (int i = 0; i < s.size(); i++) if (s[i] == s[i + 1]) count++;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s[i + 1]) s1 += s[i + 1];
		else 
		{
			if (s1.size() > s2.size())
			{
				s2 = s1;
				imax = i;
			}
			s1 = s[imax + 1];
		}
	}
	if (count == s.size() && s.size() != 1)
	{
		cout << 0;
		return 0;
	}
	else if (s1.size() - 1 == s.size()) cout << s << " " << s.size();
	else cout << s2 << " " << s2.size();
}
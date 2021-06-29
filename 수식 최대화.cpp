#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate(long long a, long long b, char op)
{
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
}

long long solution(string e)
{
	long long maxNum = 0;
	vector<char> operator_list = { '*','+','-' };
	vector<long long> nV;
	vector<char> opV;
	string num = "";

	for (int i = 0; i < e.size(); i++)
	{
		if (e[i] == '*' || e[i] == '+' || e[i] == '-')
		{
			nV.push_back(stoi(num));
			num = "";
			opV.push_back(e[i]);

		}
		else
			num += e[i];
	}
	nV.push_back(stoi(num));

	do 
	{
		vector<long long> tnV = nV;
		vector<char> topV = opV;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < topV.size(); j++)
			{
				if (topV[j] == operator_list[i])
				{
					tnV[j] = calculate(tnV[j], tnV[j + 1], operator_list[i]);
					tnV.erase(tnV.begin() + j + 1);
					topV.erase(topV.begin() + j);
					j--;
				}
			}
		}

		if (abs(tnV.front()) > maxNum)
			maxNum = abs(tnV.front());

	} while (next_permutation(operator_list.begin(), operator_list.end()));

	return maxNum;
}

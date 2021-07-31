#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string replaceAll(string& m, string from, string to)
{
	int pos = 0;
	while ((pos = m.find(from)) != -1)
		m.replace(pos, from.length(), to);
	return m;
}

string solution(string m, vector<string> M)
{
	string answer = "";
	pair<int, string> ans = { 0,"" };
	replaceAll(m, "A#", "a");
	replaceAll(m, "B#", "b");
	replaceAll(m, "C#", "c");
	replaceAll(m, "D#", "d");
	replaceAll(m, "E#", "e");
	replaceAll(m, "F#", "f");
	replaceAll(m, "G#", "g");

	for (int i = 0; i < M.size(); i++)
	{
		int t = 0;
		int index = 0;
		int pos = 0;

		string h1, h2, m1, m2;
		string title = "";
		string code = "";

		h1 = M[i].substr(0, 2);
		m1 = M[i].substr(3, 2);
		h2 = M[i].substr(6, 2);
		m2 = M[i].substr(9, 2);

		if (m1 > m2)
		{
			t = 60 - abs(stoi(m2) - stoi(m1));
			t = t + (stoi(h2) - stoi(h1) - 1) * 60;
		}
		else
		{
			t = stoi(m2) - stoi(m1);
			t = t + (stoi(h2) - stoi(h1)) * 60;
		}

		for (int j = 12; j < M[i].size(); j++)
		{
			if (M[i][j] == ',')
			{
				index = j + 1;
				break;
			}
			title += M[i][j];
		}

		for (int j = index; j < M[i].size(); j++)
			code += M[i][j];

		replaceAll(code, "A#", "a");
		replaceAll(code, "B#", "b");
		replaceAll(code, "C#", "c");
		replaceAll(code, "D#", "d");
		replaceAll(code, "E#", "e");
		replaceAll(code, "F#", "f");
		replaceAll(code, "G#", "g");

		if (t > code.size())
		{
			string tempt = code;
			index = 0;
			for (int i = code.size(); i < t; i++)
			{
				code += tempt[index];
				index = (index + 1) % tempt.size();
			}
		}

		else
		{
			string tempt = "";
			for (int i = 0; i < t; i++)
			{
				tempt += code[i];
			}
			code = tempt;
		}

		index = code.find(m);
		if (index != -1 && ans.first < t)
		{
			ans.first = t;
			ans.second = title;
		}

	}

	if (ans.second == "")
		answer = "(None)";
	else
		answer = ans.second;

	return answer;
}

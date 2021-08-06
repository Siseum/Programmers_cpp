#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";

    int Max = -1234567890;
    int Min = 1234567890;

    string tempt = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            tempt.push_back(s[i]);
            if (i != s.size() - 1)
                continue;
        }

        int ntempt = stoi(tempt);
        Max = max(ntempt, Max);
        Min = min(ntempt, Min);
        tempt = "";
    }

    answer += to_string(Min);
    answer += " ";
    answer += to_string(Max);

    return answer;
}

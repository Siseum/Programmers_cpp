#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(vector<int> a, vector<int>b)
{
    if (a.size() < b.size())
        return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>>tempt;
    vector<int> t;
    string tStr;

    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            tStr.push_back(s[i]);

        else if (s[i] == ',' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
        {
            t.push_back(stoi(tStr));
            tStr.clear();
        }
        else if ((s[i] == '}' && s[i + 1] == ',') || (s[i] == '}' && s[i + 1] == '}'))
        {
            t.push_back(stoi(tStr));
            tempt.push_back(t);
            tStr.clear();
            t.clear();
        }

    }

    sort(tempt.begin(), tempt.end(), Compare);

    answer.push_back(tempt[0][0]);
    for (int i = 1; i < tempt.size(); i++)
    {
        for (int j = 0; j < tempt[i].size(); j++)
        {
            if (find(tempt[i - 1].begin(), tempt[i - 1].end(), tempt[i][j]) == tempt[i - 1].end())
            {
                answer.push_back(tempt[i][j]);
                break;
            }
        }
    }

    return answer;
}

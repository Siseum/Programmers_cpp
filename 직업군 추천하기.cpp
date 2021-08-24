#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    vector<string> answer;

    stringstream ss;

    map<string, int> p;
    map<string, int> result;

    int Max = 0;

    for (int i = 0; i < languages.size(); i++)
    {
        p[languages[i]] = preference[i];
    }

    for (int i = 0; i < table.size(); i++)
    {
        ss.str(table[i]);
        ss.clear();
        int Count = 5;
        int tMax = 0;

        string tCategory = "";
        string tempt = "";

        ss >> tCategory;

        while (ss >> tempt)
        {
            if (p[tempt] != 0)
            {
                result[tCategory] += (Count)*p[tempt];
                tMax += (Count)*p[tempt];
            }
            Count--;
        }

        Max = max(Max, tMax);
    }

    for (auto iter : result)
    {
        if (Max == iter.second)
            answer.push_back(iter.first);
    }

    sort(answer.begin(), answer.end());

    return answer[0];
}

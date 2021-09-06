#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info
{
    int Number;
    int Weight;
    double Rate;
    int Count;
};

bool Sort(Info a, Info b)
{
    if (a.Rate > b.Rate)
        return true;

    if (a.Rate == b.Rate)
    {
        if (a.Count > b.Count)
            return true;

        if (a.Count == b.Count)
        {
            if (a.Weight > b.Weight)
                return true;
            
            if (a.Weight == b.Weight)
            {
                if (a.Number < b.Number)
                    return true;
            }
        }
    }

    return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head)
{
    vector<int> answer;

    int n = weights.size();

    vector<Info>info(n);

    for (int i = 0; i < n; i++)
    {
        info[i].Number = i+1;
        info[i].Weight = weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int win = 0;
        int hWin = 0;
        for (int j = 0; j < head2head[i].size(); j++)
        {
            if (head2head[i][j] != 'N')
                count++;
            if (head2head[i][j] == 'W')
            {
                win++;
                if (info[i].Weight < info[j].Weight)
                    hWin++;
            }
        }
        info[i].Count = hWin;

        if (count == 0)
            info[i].Rate = 0;
        else
            info[i].Rate = static_cast<double>(win) / count;
    }

    sort(info.begin(), info.end(), Sort);

    for (int i = 0; i < n; i++)
        answer.push_back(info[i].Number);

    return answer;
}

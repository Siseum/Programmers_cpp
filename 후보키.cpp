#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool possi(vector<int> answer, int n)
{
    for (int i = 0; i < answer.size(); i++)
    {
        if ((answer[i] & n) == answer[i])
            return false;
    }
    return true;
}

int solution(vector<vector<string>> r) 
{
    int N = r.size();
    int rN = r[0].size();
    vector<int> answer;

    for (int i = 1; i < (1 << rN); i++)
    {
        set<string> s;

        for (int j = 0; j < N; j++)
        {
            string tempt = "";

            for (int k = 0; k < rN; k++)
            {
                if (i & (1 << k))
                    tempt = tempt + r[j][k];
            }
            s.insert(tempt);
        }

        if (s.size() == N && possi(answer, i))
            answer.push_back(i);

    }

    return answer.size();
}

#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    bool check[100] = { 0, };
    vector<pair<int, int>> v;
    int p = priorities.size();

    for (int i = 1; i <= p; i++)
        v.push_back({ i,priorities[i - 1] });

    int index = 0;

    for (int i = 1; i <= p; i++)
    {
        int Priority = 0;
        int tempt = index % p;

        for (int j = 1; j <= p; j++)
        {
            tempt = tempt % p;
            if (check[tempt])
            {
                tempt++;
                continue;
            }
            if (Priority < v[tempt].second)
            {
                Priority = v[tempt].second;
                index = tempt;
            }
            tempt++;
        }

        v[index].second = i;
        check[index] = true;
    }

    answer = v[location].second;

    return answer;
}

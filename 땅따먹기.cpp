#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); i++)
    {
        land[i][0] += max({ land[i - 1][1],land[i - 1][2],land[i - 1][3] });
        land[i][1] += max({ land[i - 1][0],land[i - 1][2],land[i - 1][3] });
        land[i][2] += max({ land[i - 1][0],land[i - 1][1],land[i - 1][3] });
        land[i][3] += max({ land[i - 1][0],land[i - 1][1],land[i - 1][2] });
    }

    int n = land.size() - 1;

    answer = max({ land[n][0],land[n][1],land[n][2],land[n][3] });

    return answer;
}

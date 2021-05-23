#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
    if (a.second > b.second)
        return true;

    else if (a.second == b.second)
    {
        if (a.first < b.first)
            return true;
        else
            return false;
    }

    else
        return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> rate;

    int Count[501] = { 0, };
    int vN = stages.size();
    int modN = vN;

    for (int i = 0; i < vN; i++)
        Count[stages[i]]++;

    for (int i = 1; i <= N; i++)
    {
        modN = modN - Count[i - 1];
        if (modN != 0)
            rate.push_back(make_pair(i, double(Count[i]) / modN));
        else
            rate.push_back(make_pair(i, 0));
    }

    sort(rate.begin(), rate.end(), compare);

    for (int i = 0; i < N; i++)
        answer.push_back(rate[i].first);

    return answer;
}

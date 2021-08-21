#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;
    long long sum = 0;

    priority_queue<int, vector<int>, less<int>> q;

    for (int i = 0; i < works.size(); i++)
    {
        sum += works[i];
        q.push(works[i]);
    }

    if (sum < n)
        return 0;

    for (int i = 0; i < n; i++)
    {
        int tempt = q.top();
        q.pop();
        q.push(tempt - 1);
    }

    for (int i = 0; i < works.size(); i++)
    {
        long long tempt = q.top();
        answer += tempt * tempt;
        q.pop();
    }

    return answer;
}

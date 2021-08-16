#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k)
{
    vector<int> answer;
    vector<int> number;
    long long tempt = 1;
    k = k - 1;

    for (int i = 1; i <= n; i++)
        number.push_back(i);

    for (int i = n - 1; i >= 1; i--)
        tempt *= i;

    for (int i = n - 1; i >= 1; i--)
    {
        long long r1 = k / tempt;
        k = k % tempt;

        tempt = tempt / i;

        answer.push_back(number[r1]);
        number.erase(number.begin() + r1);
    }
    answer.push_back(number[0]);

    return answer;
}

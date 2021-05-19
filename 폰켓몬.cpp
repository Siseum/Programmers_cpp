#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    set<int> a;

    for (int i = 0; i < N; i++)
        a.insert(nums[i]);

    if (a.size() <= N / 2)
        answer = a.size();
    else
        answer = N / 2;

    return answer;
}

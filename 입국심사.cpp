#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long start = 1;
    long long end = 0;
    long long N = n;

    sort(times.begin(), times.end(), less<int>());

    end = times[0] * N;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long count = 0;
        for (int i = 0; i < times.size(); i++)
            count = count + (mid / times[i]);

        if (count < N)
            start = mid + 1;
        else
            end = mid - 1;
    }

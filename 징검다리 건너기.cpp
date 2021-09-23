#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool BinarySearch(int& n, int& k, vector<int>& v)
{
    int count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] - n <= 0)
            count++;
        else
            count = 0;

        if (count >= k)
            return true;
    }

    return false;
}

int solution(vector<int> stones, int k)
{
    int first = 1;
    int last = *max_element(stones.begin(), stones.end());

    while (first <= last)
    {
        int mid = (first + last) / 2;

        if (BinarySearch(mid, k, stones))
            last = mid - 1;
        else
            first = mid + 1;

    }

    return first;
}

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long n = numbers[i] + 1;
        int Count = 0;
        long long tempt = n;

        while (1)
        {
            Count++;
            if (tempt & 1)
                break;
            tempt = tempt >> 1;
        }

        if (Count >= 2)
            n = n + (static_cast<long long>(1) << (Count - 2)) - 1;

        answer.push_back(n);
    }

    return answer;
}

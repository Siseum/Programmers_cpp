#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
int n;

void Hanoi(int from, int by, int to, int Count)
{
    if (Count == 0)
        return;

    Hanoi(from, to, by, Count - 1);

    answer.push_back({ from,to });

    Hanoi(by, from, to, Count - 1);
}

vector<vector<int>> solution(int N) {
    n = N;
    Hanoi(1, 2, 3, n);

    return answer;
}

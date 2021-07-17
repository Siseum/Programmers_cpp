#include <string>
#include <vector>

using namespace std;

int arr[1000][1000] = { 0, };

vector<int> solution(int n) {
    vector<int> answer;

    int dir = 0;
    int i = 0;
    int j = 0;

    int Number = (n) * (n + 1) / 2;

    for (int number = 1; number <= Number; number++)
    {
        if (dir == 0)
        {
            arr[i][j] = number;
            i++;
            if (i >= n || arr[i][j] != 0)
            {
                dir = (dir + 1) % 3;
                i--;
                j++;
            }
        }
        else if (dir == 1)
        {
            arr[i][j] = number;
            j++;
            if (j >= n || arr[i][j] != 0)
            {
                dir = (dir + 1) % 3;
                i--;
                j = j - 2;
            }
        }
        else if (dir == 2)
        {
            arr[i][j] = number;
            i--;
            j--;
            if (arr[i][j] != 0)
            {
                dir = (dir + 1) % 3;
                i = i + 2;
                j++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);
    }

    return answer;
}

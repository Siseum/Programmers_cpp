#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    int Max = 0;
    int Min = 0;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for (auto operation : operations)
    {
        if (operation[0] == 'I')
        {
            string number = "";
            for (int i = 2; i < operation.size(); i++)
                number.push_back(operation[i]);

            pq1.push(stoi(number));
            pq2.push(stoi(number));

            Max = pq1.top();
            Min = pq2.top();
        }
        else if (operation == "D 1")
        {
            if (pq1.empty())
                continue;

            if (Max == Min)
            {
                Max = 0;
                Min = 0;
                pq1 = priority_queue<int>();
                pq2 = priority_queue<int, vector<int>, greater<int>>();
            }
            else
            {
                pq1.pop();
                if (pq1.empty())
                    Max = 0;
                else
                    Max = pq1.top();
            }
        }
        else if (operation == "D -1")
        {
            if (pq2.empty())
                continue;
            if (Max == Min)
            {
                Max = 0;
                Min = 0;
                pq1 = priority_queue<int>();
                pq2 = priority_queue<int, vector<int>, greater<int>>();
            }
            else
            {
                pq2.pop();
                if (pq2.empty())
                    Min = 0;
                else
                    Min = pq2.top();
            }

        }
    }

    answer.push_back(Max);
    answer.push_back(Min);

    return answer;
}

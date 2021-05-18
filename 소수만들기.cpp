#include <vector>
#include <iostream>
using namespace std;

bool EvenNumber[50001];
bool visit[50001];
int vlen;
vector<int> v;
bool is_end;
int answer;

void CalSosu()
{
    for (int i = 2; i < 50000; i++)
    {
        if (EvenNumber[i])
            continue;

        int index = 2;

        while (index * i <= 50000)
        {
            EvenNumber[index * i] = true;
            index++;
        }
    }
}

void dfs(int Start, int Count, int tSum)
{

    if (Count == 3)
    {
        if (EvenNumber[tSum] == false)
        {
            answer++;
        }
        return;
    }

    for (int i = Start; i < vlen; i++)
    {
        if (visit[v[i]] == 0)
        {
            visit[v[i]] = true;
            dfs(i + 1, Count + 1, tSum + v[i]);
            visit[v[i]] = false;
        }
    }
}

int solution(vector<int> nums) {

    vlen = nums.size();
    v = nums;

    CalSosu();

    dfs(0, 0, 0);
    
    return answer;
}

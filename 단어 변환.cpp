#include <string>
#include <vector>

using namespace std;

string Begin;
string Target;
vector<string> Words;
vector<bool> Check;
bool isOk = false;
int answer = 1234567890;

void dfs(string begin, int Count)
{
    if (begin == Target)
    {
        answer = min(answer, Count);
        isOk = true;
        return;
    }

    for (int i = 0; i < Words.size(); i++)
    {
        int sameCount = 0;

        if (Check[i] == true)
            continue;

        for (int j = 0; j < begin.size(); j++)
        {
            if (begin[j] == Words[i][j])
                sameCount++;
        }

        if ((begin.size() - sameCount) == 1)
        {
            Check[i] = true;
            dfs(Words[i], Count + 1);
            Check[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    Begin = begin;
    Target = target;
    Words = words;

    Check.resize(Words.size(), false);

    dfs(Begin, 0);
    
    if(!isOk)
        answer = 0;

    return answer;
}

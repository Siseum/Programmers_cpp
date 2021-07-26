#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> tree) 
{
    int answer = 0;

    for (int i = 0; i < tree.size(); i++)
    {
        bool is_Count = true;
        for (int j = 0; j < tree[i].size(); j++)
        {
            if (find(skill.begin(), skill.end(), tree[i][j]) == skill.end())
            {
                tree[i].erase(tree[i].begin() + j);
                j--;
            }
        }
        for (int j = 0; j < tree[i].size(); j++)
        {
            if (tree[i][j] != skill[j])
            {
                is_Count = false;
                break;
            }
        }
        if(is_Count)
            answer++;
    }

    return answer;
}

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map <string, int> info;
    vector<string> name;

    for (int i = 0; i < clothes.size(); i++)
    {
        string s = clothes[i][1];
        if (info[s] == 0)
            name.push_back(s);

        info[s]++;
    }
    
    for (int i = 0; i < name.size(); i++)
        answer = answer * (info[name[i]] + 1);

    return answer-1;
}

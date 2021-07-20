#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    unordered_map<string, int> m;

    m[words[0]]++;

    for (int i = 1; i < words.size(); i++)
    {
        if (words[i - 1][words[i - 1].size() - 1] != words[i][0])
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        else if (m[words[i]] != 0)
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        m[words[i]]++;
    }

    answer.push_back(0);
    answer.push_back(0);

    return answer;
}

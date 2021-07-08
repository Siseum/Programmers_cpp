#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int N = 10000000;
bool check[N] = { true,true, };


int solution(string numbers) {
    int answer = 0;
    int MaxN=0;
    
    sort(numbers.begin(), numbers.end());

    set<int> tempt;

    do
    {
        string tStr = "";
        for (int i = 0; i < numbers.size(); i++)
        {
            tStr += numbers[i];
            tempt.insert(stoi(tStr));
            MaxN=max(MaxN,stoi(tStr));
        }

    } while (next_permutation(numbers.begin(), numbers.end()));
    
    for (int i = 2; i <= MaxN; i++)
    {
        if (check[i] == false)
        {
            for (int j = 2; j*i <= MaxN; j++)
                check[i * j] = true;
        }
    }

    for (auto iter = tempt.begin(); iter != tempt.end(); iter++)
    {
        if (check[*iter]==false)
            answer++;
    }

    return answer;
}

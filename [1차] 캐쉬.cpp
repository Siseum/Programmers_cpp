#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<string> cache(cacheSize);
    vector<int> v;
    int index = 0;

    for (int i = 0; i < cities.size(); i++)
    {
        string tempt = "";
        for (int j = 0; j < cities[i].size(); j++) tempt.push_back(toupper(cities[i][j]));

        auto iter = find(cache.begin(), cache.end(), tempt);
        if (iter == cache.end())
        {
            answer += 5;
            if (cacheSize <= 0)
                continue;

            if (v.size() < cacheSize)
            {
                cache[index] = tempt;
                v.push_back(index);
                index = (index + 1) % cacheSize;
            }

            else
            {
                index = v[0];
                cache[index] = tempt;
                v.erase(v.begin());
                v.push_back(index);
            }

        }
        else
        {
            answer += 1;
            int index2 = find(v.begin(), v.end(), (iter - cache.begin())) - v.begin();
            int n = v[index2];
            v.erase(v.begin() + index2);
            v.push_back(n);
        }

    }

    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer = {};
    
    for(int i=0;i<orders.size();i++)
        sort(orders[i].begin(),orders[i].end());

    for (int i = 0; i < course.size(); i++)
    {
        int L = course[i];
        set<string> tempt = {};
        for (int j = 0; j < orders.size(); j++)
        {
            vector<bool>check(orders[j].size(),true);
            string menu = orders[j];
            if (menu.size() < L)
                continue;
            for (int k = 0; k < L; k++)
                check[k] = false;

            do
            {
                string t = "";
                for (int k = 0; k < menu.size(); k++)
                {
                    if (check[k] == false)
                        t.push_back(menu[k]);
                }
                tempt.insert(t);
            } while (next_permutation(check.begin(), check.end()));
        }

        vector<pair<string, int>>vp = {};
        int Max = 0;

        for (set<string>::iterator iter = tempt.begin(); iter != tempt.end(); iter++)
            vp.push_back({ *iter,0 });

        for (int i = 0; i < vp.size(); i++)
        {
            for (int j = 0; j < orders.size(); j++)
            {
                bool is_check = true;
                for (int k = 0; k < L; k++)
                {
                    if (find(orders[j].begin(), orders[j].end(), vp[i].first[k]) == orders[j].end())
                    {
                        is_check = false;
                        break;
                    }
                }
                if (is_check)
                {
                    vp[i].second++;
                    Max = max(Max, vp[i].second);
                }
            }  
        }
        for (int i = 0; i < vp.size(); i++)
        {
            if (vp[i].second == Max && vp[i].second>=2)
                answer.push_back(vp[i].first);
        }
    }

    sort(answer.begin(), answer.end());
    
    return answer;
}

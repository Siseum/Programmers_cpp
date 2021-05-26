#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> tempt;
    
    for(int i=0;i<numbers.size();i++)
    {
        for(int j=i+1;j<numbers.size();j++)
            tempt.insert(numbers[i]+numbers[j]);
    }
    
    answer.assign(tempt.begin(),tempt.end());
    
    sort(answer.begin(),answer.end());
    
    return answer;
}

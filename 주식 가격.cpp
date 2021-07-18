#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p) {
    vector<int> answer;
    
    for(int i=0;i<p.size();i++)
    {
        int Count =0;
        
        for(int j=i+1;j<p.size();j++)
        {
            if(p[i]<=p[j])
                Count++;
            else
            {
                Count++;
                break;
            }
        }            
        answer.push_back(Count);
    }
        
    return answer;
}

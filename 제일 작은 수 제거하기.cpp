#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int index=0;
    int Min=arr[0];
    
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<Min)
        {
            Min=arr[i];
            index=i;
        }
    }
    
    arr.erase(arr.begin()+index);
    
    if(arr.size()==0)
        answer.push_back(-1);
    
    else
    {
        for(int i=0;i<arr.size();i++)
            answer.push_back(arr[i]);
    }
    
    return answer;
}

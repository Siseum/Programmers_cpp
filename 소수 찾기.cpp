#include <string>
#include <vector>

using namespace std;

int arr[1000001];

int solution(int n) {
    int answer = 0;
    
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==1)
            continue;
        for(int j=2*i;j<=n;j=j+i)
            arr[j]=1;
    }        
    
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==0)
            answer++;
    }
    
    return answer;
}

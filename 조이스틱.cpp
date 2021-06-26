#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int n = name.size();
    
    int turn = n-1;
    
    for(int i=0;i<n;i++)
    {
        int start = name[i]-'A';
        int end = 'Z'-name[i]+1;
        
        answer += min(start,end);
        
        int next =i+1;
        while(next<n && name[next]=='A')
            next++;
        
        turn = min(turn,i + n-next + min(i,n-next));
    }
    
    answer += turn;
    
    return answer;
}

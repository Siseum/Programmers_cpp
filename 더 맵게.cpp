#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    
    while(1)
    {
        if(pq.top() >= K)
            break;
        if(pq.size() == 1)
        {
            answer=-1;
            break;
        }
        
        answer++;
        int n = pq.top();
        pq.pop();
        n = n + pq.top()*2;
        pq.pop();
        pq.push(n);
    }
    
    return answer;
}

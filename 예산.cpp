#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int N= d.size();
    int Sum=0;
    sort(d.begin(),d.end());
    
    for(int i=0;i<N;i++)
    {
        if(Sum+d[i]<=budget)
        {            
            Sum=Sum+d[i];
            answer++;
        }
    }
     
    return answer;
}

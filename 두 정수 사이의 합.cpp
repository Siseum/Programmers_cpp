#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a>b)
    {
        int tempt=a;
        a=b;
        b=tempt;;
    }
    
    for(int i=a;i<=b;i++)
        answer+=i;
    
    return answer;
}

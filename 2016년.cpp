#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int n=b;
    
    for(int i=1;i<a;i++)
    {
        if(i == 1 || i==3 || i==5 || i==7 
           || i==8 || i==10 || i ==12)
            n+=31;
        else if(i==4 || i==6|| i==9|| i==11)
            n+=30;
        else
            n+=29;
    }
    
    n = n%7;
    
    if(n==1)
        answer="FRI";
    else if(n==2)
        answer = "SAT";
    else if(n==3)
        answer = "SUN";
    else if(n==4)
        answer = "MON";
    else if(n==5)
        answer = "TUE";
    else if(n==6)
        answer = "WED";
    else if(n==0)
        answer = "THU";
    
    return answer;
}

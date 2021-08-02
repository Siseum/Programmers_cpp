using namespace std;

long long solution(int price, int money, int count)
{
    long long p = price;
    long long m = money;
    long long c = count;
    
    long long answer = p * ((c) * (c+1) / 2) - m;
    
    if(answer <= 0)
        answer = 0;
 
    return answer;
}

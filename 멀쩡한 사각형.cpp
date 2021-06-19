using namespace std;

long long solution(int w, int h) {
    long long W = w;
    long long H = h;

    long long answer = W * H;

    if (W > H)
    {
        long long tempt = W;
        W = H;
        W = tempt;
    }

    long long n = W + H;
    long long num1 = H;
    long long num2 = W;

    while (num2 != 0)
    {
        long long tempt = num1 % num2;
        num1 = num2;
        num2 = tempt;
    }

    n = n - num1;
    answer = answer - n;

    return answer;
}

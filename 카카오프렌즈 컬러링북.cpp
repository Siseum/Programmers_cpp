#include <vector>

using namespace std;

bool visit[100][100] ={0,};
int tCount = 0;
int M=0;
int N=0;
int number=0;

void dfs(vector<vector<int>> picture, int ti, int tj)
{
    tCount++;
    
    // 상
    if(ti-1>=0 && tj < N && visit[ti-1][tj]==false && picture[ti-1][tj]==number)
    {
        visit[ti-1][tj]=true;
        dfs(picture, ti-1,tj);
    }
    
    // 하
    if(ti+1 < M && tj < N && visit[ti+1][tj]==false && picture[ti+1][tj]==number)
    {
        visit[ti+1][tj]=true;
        dfs(picture, ti+1,tj);
    }
    
    // 좌
    if(ti < M && tj-1 >=0 && visit[ti][tj-1]==false && picture[ti][tj-1]==number)
    {
        visit[ti][tj-1]=true;
        dfs(picture, ti,tj-1);
    }
    
    // 우
    if(ti < M && tj+1 < N && visit[ti][tj+1]==false && picture[ti][tj+1]==number)
    {
        visit[ti][tj+1]=true;
        dfs(picture, ti,tj+1);
    }
}


vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
    vector<int> answer(2);
    
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            visit[i][j]=false;
    
    M=m;
    N=n;
    
    int Count=0;
    int rCount=0;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(picture[i][j] ==0 || visit[i][j] ==true)
                continue;
            
            rCount++;
            tCount = 0;
            number = picture[i][j];
            visit[i][j]=true;
            
            dfs(picture,i,j);
            
            Count = max(Count,tCount);    
        }
    }
    
    answer[0]=rCount;
    answer[1]=Count;
    
    return answer;
}

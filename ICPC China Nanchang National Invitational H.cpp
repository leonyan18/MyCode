#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
#include <set>
#include <cstdlib>
#include <map>
#include <queue>
#define MaxN 0x7fffffff
#define MinN -0x7fffffff
#define Clear(x) memset(x,0,sizeof(x))
const long long INF=1e16;
const int maxn=500010;
long long a[maxn];
long long Sum[maxn];
int dp[maxn][21];
long long M;
int T;
int L;
int R;
int p;
void RMQ(int N)
{
    for(int i=1;i<=N;i++)
        dp[i][0]=a[i];//³õÊ¼»¯
    for(int j=1;(1<<j)<=N;j++)
    {
    	for(int i=1;i+(1<<j)-1<=N;i++)
        {
        	dp[i][j]=min(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
//        	printf("i:%d j:%d: %d %d  ",i,j,dp[i][j],(Sum[i+(1<<j)-1]-Sum[i-1]));
        	M=max(M,dp[i][j]*(Sum[i+(1<<j)-1]-Sum[i-1]));
//        	printf("%lld %lld",(long long)dp[i][j]*(Sum[i+(1<<j)-1]-Sum[i-1]),M);
        }
//        cout<<endl;
    }
        
       
}

void init()
{
    Sum[0]=0;
    M=-INF;
}

int main()
{
#ifdef OUT
    freopen("coco.txt","r",stdin);
    freopen("lala.txt","w",stdout);
#endif
		scanf("%d",&T);	
        init();
        for(int i=1;i<=T;i++)
        {
            scanf("%lld",&a[i]); 
            Sum[i]=Sum[i-1]+a[i];
        }
        RMQ(T);
        //solve(1,T);
        cout<<M<<endl;
        //cout<<L<<" "<<R<<endl;

    

    return 0;
}
/*
5
-1 -2 -3 -4 5
*/

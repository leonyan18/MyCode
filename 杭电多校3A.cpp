#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
const int MAXN = 10000005;
const int INF = 0x3f3f3f3f;
 
int a[MAXN],Que[5 * MAXN];
 
int main(void)
{
    int n,m,k,p,q,r,MOD;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d %d %d %d %d",&n,&m,&k,&p,&q,&r,&MOD);
        for(int i = 1; i <= k; i++) scanf("%d",&a[i]);
        for(int i = k + 1; i <= n; i++) {
            a[i]=(1LL * p * a[i-1] + 1LL * q * i + 1LL * r) % MOD;
        }
        int Front = 0,Tail = 0;
        LL ans1 = 0,ans2 = 0;
        for(int i = n; i >= 1; i--) {
            while(Front < Tail && a[Que[Tail - 1]] <= a[i]) Tail--;
            Que[Tail++] = i;
            while(Que[Front] > i + m - 1) Front++;
            if(i <= n - m + 1) {
                ans1 += (1LL * a[Que[Front]]) ^ (1LL * i);
                ans2 += (1LL * (Tail - Front)) ^ (1LL * i);
            }
        }
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
 


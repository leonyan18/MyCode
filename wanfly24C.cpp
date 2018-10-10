#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int dp[105][100005];
int a[105];
int main(){
    //±æµÿ≤‚ ‘
    #ifdef ONLINE_JUDGE
    #else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
    #endif
    int m,n;
    scanf("%d%d",&n,&m);
    int sum=0;
    rep(i,0,n){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    memset(dp, 0x8f, sizeof(dp));
    dp[0][0] = 0;
    rep(i,0,n){
        rep(j,0,sum+1){
                dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
                int val=j+a[i];
                dp[i+1][val]=max(dp[i+1][val],dp[i][j]+a[i]);
                val=abs(j-a[i]);
                dp[i+1][val]=max(dp[i+1][val],dp[i][j]+a[i]);         
        }
    }
    int ans=0;
    rep(j,0,m+1){
        ans=max(ans,dp[n][j]);
    }
    cout<<ans<<endl;
}

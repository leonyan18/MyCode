#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=2e5+5;
const int mod=1e8+7;
const int top=200000;
int dp[305][maxn*2+666];
int a[305];
int main(){
    //本地测试
    #ifdef ONLINE_JUDGE
    #else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);//取消同步
    std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
    int n;
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
    }
    dp[0][top]=1;
    rep(i,1,n+1){
        rep(j,0,top*2){
//            dp[i&1][j]=0;
            if(j==top+666){
                continue;
            }
            if(top*2-j!=top+666){
                dp[i][j]+=dp[(i-1)][top*2-j]%mod;
            }
            if(j>=a[i]&&dp[(i-1)][j-a[i]]>0){
                dp[i][j]+=dp[(i-1) ][j-a[i]]%mod;
            }
            dp[i ][j]=dp[i ][j]%mod;
//          if(dp[i ][j]>0){
//              cout<< (i ) << " "<<j<<" "<< (dp[(i-1) ][j]) <<endl;
//          }
        }  
    }
    cout<<dp[n][top-666]%mod<<endl;
}

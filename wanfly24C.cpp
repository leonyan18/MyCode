#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int dp[105][1000];
int a[105];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int m,n;
	cin>>n>>m;
	int sum=0;
	rep(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}
	clr(dp);
	rep(i,0,n){
		rep(j,0,sum+1){
			if(dp[i][j]||j==0){
				dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
				int val=j+a[i];
				dp[i+1][val]=max(dp[i+1][val],dp[i][j]+a[i]);
				val=j-a[i];
				if(val<0)
				val=val*(-1);
				dp[i+1][val]=max(dp[i+1][val],dp[i][j]+a[i]);			
			}
		}
	}
	int ans=0;
	rep(i,0,n){
		rep(j,0,m+1){
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
}




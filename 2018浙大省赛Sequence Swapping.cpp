#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1005;
ll v[maxn];
char s[maxn];
ll sl[maxn];
ll sr[maxn];
ll sum[maxn];
ll pos[maxn];
ll dp[maxn][maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		clr(sl);
		clr(sr);
		clr(s);
		clr(v);
		clr(dp);
		int n;
		cin>>n;
		cin>>s;
		rep(i,0,n){
			cin>>v[i];
		}
		int lenr=0;
		int lenl=0;
		rep(i,0,n){
			if(s[i]=='('){
				pos[lenl++]=i;
			}else{
				sum[++lenr]=sum[lenr-1]+v[i];
			}			
		}
		ll ans=0;
		per(i,0,lenl){
			per(j,0,n-(lenl-i-1)){
				if(j>pos[i]){
					int start=pos[i]-i;
					int end=j-i;
					if(j!=n-(lenl-i-1)-1) 
					dp[i][j]=max(dp[i+1][j+1]+(sum[end]-sum[start])*v[pos[i]],dp[i][j+1]);
					else
					dp[i][j]=dp[i+1][j+1]+(sum[end]-sum[start])*v[pos[i]];
				}else
					dp[i][j]=max(dp[i+1][j+1],dp[i][j+1]);
//				cout<<dp[i][j]<<" ";
				ans=max(ans,dp[i][j]);
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	} 
}

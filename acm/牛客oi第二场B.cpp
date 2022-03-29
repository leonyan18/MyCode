#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=30+5;
int n,m;
bool rec[maxn][maxn];
bool vis[maxn];
ll ans=0;
void dfs(int pos, int len){
//	cout<<pos<<" "<<len<<endl;
	if(len>m)
		return;
	if(pos==n&&len==m){
		ans++;
		return;
	}
	rep(i,1,n+1){
		if(rec[pos][i]&&vis[i]==0){
			vis[i]=1;
			dfs(i,len+1);
			vis[i]=0;
		}
	}
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	cin>>n>>m;
	rep(i,1,n+1){
		rep(j,1,n+1){
			cin>>rec[i][j];
		}
	}
	clr(vis);
	dfs(1,0); 
	cout<<ans<<endl;          
}




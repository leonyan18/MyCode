#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int mmap[5005][5005];
int vis[5005][5005];
ll ans;
int n,m;
struct node{
	int pos;
	int w;
	node(int a,int b){
		pos=a;
		w=b;
	}
};
vector<node> a[5005];
void dfs(int pos,int num,ll sum){
	if(num==n){
		ans=min(sum,ans);
		return;
	}	
	rep(i,0,a[pos].size()){
		int w=a[pos][i].w;
		int next=a[pos][i].pos;
		if(w!=0){
			if(sum+w<ans&&vis[pos][next]==0){
				vis[pos][next]=1;
				if(vis[next][pos]==0)
				dfs(next,num+1,sum+w);
				else
				dfs(next,num,sum+w);
				vis[pos][next]=0;
			}
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
	clr(mmap);
	rep(i,0,n-1){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		a[u].push_back(node(v,w));
		a[v].push_back(node(u,w));
	}
	ans=5005*1e9;
	dfs(m,1,0);
	cout<<ans<<endl;
}




#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
int edge[maxn][100];
int edgelen[maxn];
int vis[maxn];
int dfs(int pos){
	vis[pos]=1;
	int sum=1;
	rep(i,0,edgelen[pos]){
		if(vis[edge[pos][i]]==0)
			sum+=dfs(edge[pos][i]);
	}
	return sum;
}
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
	clr(edge);
	clr(edgelen);
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		edge[x][edgelen[x]++]=y;
		edge[y][edgelen[y]++]=x;
	}
	int ans=0;
	vis[1]=1;
	rep(i,0,edgelen[1]){
		ans=max(ans,dfs(edge[1][i]));
	}
	cout<<ans<<endl;
}




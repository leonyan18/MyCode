#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
#define tomax(x) memset(x,0x3f,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
struct Edge{
	ll v,w;
	Edge(ll v,ll w):v(v),w(w){} 
};
 
struct Node{
	ll u;
	ll w;
	ll t;
	Node(){}
	Node(ll u,ll w,ll t):u(u),w(w),t(t){}
	bool operator<(const Node &a)const 
	{
		if(w!=a.w)
		return w>a.w;
		else if(t!=a.t)
		return t>a.t;
	}
};
bool cmp(Edge a,Edge b){
	if(a.v==b.v){
		return a.w<b.w;
	}
	return a.v<b.v;
}
vector<Edge>g[maxn];
ll dis[maxn][15];
bool vis[N][11];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	int t;
	scanf("%d",&t);
	while(t--){
		memset(vis,false,sizeof(vis));
		tomax(dis);
		ll n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		rep(i,0,n){
			g[i].clear();
		}
		rep(i,0,m){
			ll u,v,w;
			scanf("%lld%lld%lld",&u,&v,&w);
			g[u].push_back(Edge(v,w));
		}
		rep(i,0,n){
			sort(g[i].begin(),g[i].end(),cmp);
			int len=g[i].size();
			int pos=1;
			rep(j,1,len){
				if(g[i][pos-1].v==g[i][pos].v)
					g[i].erase(g[i].begin()+pos);
				else{
					pos++;
				}
			}
		}
		priority_queue<Node> q;
		q.push(Node(1,0,0));
		dis[1][0]=0;
		while(!q.empty()){
			Node to=q.top();
			int pos=to.u;
			int time=to.t;
			ll spend=to.w;
			q.pop();
			rep(i,0,g[pos].size()){
				int nextv=g[pos][i].v;
				int nextw=g[pos][i].w;
				if(dis[nextv][time]>spend+g[pos][i].w){
					dis[nextv][time]=spend+nextw;
					q.push(Node(nextv,spend+nextw,time));
				}
				if(z==k)//如果已经使k条边为0，就跳过 
				  continue;	
				if(dis[g[pos][i].v][time+1]>spend){
					dis[g[pos][i].v][time+1]=spend;
					q.push(Node(g[pos][i].v,spend,time+1));
				}
			}
		}
		cout<<dis[n][k]<<endl;
	} 
}

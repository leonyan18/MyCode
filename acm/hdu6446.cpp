#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
const int mod=1e9+7;
struct node{
	int end;
	int len;
	node(int a,int b){
		end=a;
		len=b;
	}
};
ll n;
vector<node> tree[maxn];
ll sum[maxn]; 
ll ans;
ll dfs(ll pre,ll cur,ll len){
	rep(i,0,tree[cur].size()){
		if(tree[cur][i].end!=pre){
			dfs(cur,tree[cur][i].end,tree[cur][i].len);
		}
	}
	sum[cur]=1;
	rep(i,0,tree[cur].size()){
		sum[cur]+=sum[tree[cur][i].end];
	}
	ans+=sum[cur]*(n-sum[cur])%mod*len%mod;
	ans=ans%mod;
//	cout<<pre<<" "<<cur<<" "<<ans<<endl; 
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	while(cin>>n){
		ans=0;
		clr(tree);
		clr(sum);
		rep(i,1,n){
			int x,y,z;
			cin>>x>>y>>z;
			tree[x].push_back(node(y,z));
			tree[y].push_back(node(x,z));
		}
		ll f = 1;
		for (ll i = 1 ; i <= n - 1 ; i++) f = f * i % mod;
		dfs(-1,1,0);
		cout<<ans*f%mod*2%mod<<endl;
	}
}




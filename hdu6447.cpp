#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int n;
int maxx[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void add(int pos,int val)
{
    for(int i=pos;i<=maxn;i+=lowbit(i))
        maxx[i]=max(maxx[i],val);
}
int query(int pos)
{
    int ans=0;
    for(int i=pos;i>=1;i-=lowbit(i))
        ans=max(ans,maxx[i]);
    return ans;
}
struct node{
	int x,y,v;
	node(){
	}
	node(int x,int y,int v):x(x),y(y),v(v){	
	}
}p[maxn];
bool nodecmp(node a,node b){
	if(a.x==b.x)
		return a.y>b.y;
	return a.x<b.x;
}
int posy[maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		clr(maxx);
		cin>>n;
		rep(i,0,n){
			int x,y,v;
			cin>>x>>y>>v;
			posy[i]=y;
			p[i]=node(x,y,v);
		}
		sort(p,p+n,nodecmp);
		sort(posy,posy+n);		
        int all=unique(posy,posy+n)-posy;
		rep(i,0,n){
			p[i].y=lower_bound(posy,posy+all,p[i].y)-posy+1;
		}
		rep(i,0,n){
			ll val=query(p[i].y-1)+p[i].v;
			add(p[i].y,val);
		}
		ll ans=query(maxn-1);
		cout<<ans<<endl;
	}
}




#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
struct node{
	int pos;
	int val;
	bool operator < (const node &a) const{
    	return val<a.val;
	}
};
int a[maxn];
int sum[maxn];
vector<node>  mmap[maxn];
int flag[maxn];
int f[maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,m,k,t;
	cin>>n>>m>>k>>t;
	clr(flag);
	rep(i,1,n+1){
		cin>>a[i];
	}
	rep(i,0,k){
		cin>>f[i];
		flag[f[i]]=1;
	}
	rep(i,0,m){
		int x,y,h;
		cin>>x>>y>>h;
		node temp;
		temp.pos=y;
		temp.pos=h;
		mmap[x].push_back(temp);
	}
	priority_queue<node> q;
	rep(i,0,k){
		node temp;
		temp.pos=f[i];
		temp.val=sum[f[i]];
		q.push(temp);
	}
	priority_queue<node> q;
	rep(i,1,n+1){
		node temp;
		temp.pos=i;
		temp.val=sum[i];
		q.push(temp);
	}
	while(!q.empty()&&k<n){
		
	}
}




#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int x[maxn];
int y[maxn]; 
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,m,t;
	cin>>n>>m>>t;
	rep(i,0,t){
		int op,v;
		cin>>op>>v;
		if(op==1){
			x[v]=i+1;
		}else{
			y[v]=i+1;
		}
	}
	rep(i,1,n+1){
		rep(j,1,m+1){
			if(j==1)
			cout<<max(x[i],y[j]);
			else
			cout<<" "<<max(x[i],y[j]);
		}
		cout<<endl;
	}
}




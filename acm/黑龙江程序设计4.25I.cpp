#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=500005;
ll edge[maxn];
ll ans[maxn];
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
	rep(i,1,n+1){
		for(int j=2;j*i<=n;j++){
			edge[i*j]=i;
		}
	}
	memset(ans,0,sizeof(ans));
	rep(i,2,n+1){
		ll next=edge[i];
		ans[i]=ans[next]+(next-i)*(next-i);
	}
	rep(i,1,n+1){
		if(i==1){
			cout<<ans[i];
		}else{
			cout<<" "<<ans[i];
		}
	}
} 




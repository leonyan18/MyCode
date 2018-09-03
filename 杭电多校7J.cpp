#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
ll ans[1000005];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	ll  a,b,c,d,p,n;
	cin>>a>>b>>c>>d>>p>>n;
	ans[1]=a;
	ans[2]=b;
	for(int i=3;i<=100;i++){
		ans[i]=c*ans[i-2]%mod+d*ans[i-1]%mod+p/i;
		ans[i]%=mod;
	}
	rep(i,1,101){
		cout<<ans[i]<<endl;
	}
}



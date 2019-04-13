#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
const int mod=1e9+7;
int ans[maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	rep(i,1,1000005){
		ans[i]=ans[i-1]+i;
		ans[i]%=mod; 
	}
	int n;
	cin>>n;
	ll sum=0;
	rep(i,0,n){
		ll val;
		cin>>val;
		sum+=ans[n-i]*val%mod*(i+1)%mod;
	}
	cout<<sum<<endl;
}

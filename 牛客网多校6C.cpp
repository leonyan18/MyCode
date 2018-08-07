#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
const int mod=998244353;
int inv[maxn];
void inverse(int n) {
    inv[1] = 1;
    for (int i=2; i<=n; ++i) {
        inv[i] = (ll) (mod - mod / i) * inv[mod%i] % mod;
    }
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	inverse(maxn);
	int t;
	cin>>t;
	rep(ca,1,t+1){
		ll n,m;
		cin>>n>>m;
		ll ans=m%mod;
		ll sum=m%mod;
		rep(i,1,min(n,m)){
			sum=sum*(n%mod-i)%mod*(m%mod-i)%mod*inv[i]%mod;
			ans+=sum;
			ans=ans%mod;
		}
		printf("Case #%d: %lld\n",ca,(ans+mod)%mod);
	}
}



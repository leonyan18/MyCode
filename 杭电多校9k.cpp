#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int mod=998244353;
long long  qpow(long long  a, long long b)
{
    long long ans = 1;
    a %= mod;
    while (b) {
        if (b & 1)ans = ans * a%mod;
        a = a * a%mod;
        b >>= 1;
    }
    return ans;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
//    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ll ans=qpow(2,a)*((qpow(2,b)+qpow(2,c)+b*qpow(2,c)%mod+d*qpow(2,c)%mod-b+mod-1)%mod)%mod;
		cout<<ans<<endl;
	} 
}




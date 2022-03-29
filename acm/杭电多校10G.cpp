#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
const int mod=998244353;
ll ans[maxn];
ll pow_mod(ll x, ll n){
    ll res=1;
    while(n>0){
        if(n&1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	ans[1]=0;
	ans[2]=0;
	ans[3]=1;
	ans[4]=1;
	rep(i,5,maxn-2){
		if(i%2==1)
		ans[i]= (i-2) * ans[i-1]%mod + (i-1) * ans[i-2]%mod +1;
		else
		ans[i]= (i-2) * ans[i-1]%mod + (i-1) * ans[i-2]%mod -1+mod;
		ans[i]%=mod;
	}
	ans[1]=1;
	ans[2]=1;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<ans[n]<<endl;
	}
}




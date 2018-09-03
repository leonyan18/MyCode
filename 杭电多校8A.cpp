#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int mod=998244353;
ll inv[N],fac[N],fnv[N];
ll comb(ll a,ll b) {//排列组合里的c 
    return fac[a]*fnv[b]%mod*fnv[a-b]%mod;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	inv[1]=1;
    fac[0]=fnv[0]=1;
    for (int i=2;i<=100000;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;//逆元打表 
    for (int i=1;i<=100000;i++) {
        fac[i]=fac[i-1]*i%mod;//累乘 
        fnv[i]=fnv[i-1]*inv[i]%mod;//累除 逆元变累乘 
    }
    int n,m,k,t;
    while(t--){
    	cin>>n>>m>>k;
    	int sum=0;
    	if (m>n||n*m<=k)
    		cout<<sum<endl;
    	else{
    		int big=k-k/m;
    		int small=m-big;
    		int time=min(big*(k-k/m-1),small*(k/m));
    		rep()
		}
	}
	
}



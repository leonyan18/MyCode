#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const ll mod=1000000007;
ll quick(ll a,ll b){    //快速幂 
    ll ans=1;  
    a=a%mod;  
    while(b!=0)  
    {  
      if(b&1) ans=(ans*a)%mod;  
       b>>=1;  
       a=(a*a)%mod;  
    }  
    return ans;  
} 
ll gcd(ll a,ll b) {
	return b?gcd(b,a%b):a;
} 
const int N=2000100;
ll inv[N],fac[N],fnv[N],fib[N];
ll a[N] ;
int n,k;
ll comb(ll a,ll b) {//排列组合里的c 
    return fac[a]*fnv[b]%mod*fnv[a-b]%mod;
}
int main() {
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
    inv[1]=1;
    fac[0]=fnv[0]=1;
    for (int i=2;i<=1000000;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;//逆元打表 
    for (int i=1;i<=2000000;i++) {
        fac[i]=fac[i-1]*i%mod;//累乘 
        fnv[i]=fnv[i-1]*inv[i]%mod;//累除 逆元变累乘 
    }
    fib[0]=0; fib[1]=1;
    rep(i,2,1000001) fib[i]=(fib[i-1]+fib[i-2])%(mod-1);//斐波那契打表 
    int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int> v;
		rep(i,1,n+1){//如果是约数进队 
			if(n%i==0)
				v.push_back(i);
		}
		rep(i,0,v.size()){
			a[i]=comb(n/v[i]+k-1,k-1);//约束为g的方案数 
		}
		rep(i,0,v.size()){
			per(j,i+1,v.size()){
				if(v[j]%v[i]==0){
					a[i]=a[i]-a[j]+mod;//减去重复的方案个数 
					a[i]%=mod;
				}
			}
		}
		ll sum=0;
		rep(i,0,v.size()){
			sum=(sum+a[i]*(quick(2,fib[v[i]])-1)%mod)%mod;
		}
		sum=sum*pow(comb(n+k-1,k-1),mod-2);
		cout<<sum<<endl;
	}
        //乘以总的方案个数的逆元 
}

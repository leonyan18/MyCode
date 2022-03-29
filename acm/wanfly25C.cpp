#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
const int mod=998244353;
long long quick(long long a,long long b){    //快速幂 
    long long ans=1;  
    a=a%mod;  
    while(b!=0)  
    {  
        if(b&1) ans=(ans*a)%mod;  
        b>>=1;  
        a=(a*a)%mod;  
    }  
    return ans;  
} 
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cout<<(4*quick(3,mod-2))%mod<<endl;
	cin>>t;
	while(t--){
		int x,q;
		cin>>x>>q;
		ll ans=quick((q-x),mod-2);
		cout<<ans<<endl;
	}
}




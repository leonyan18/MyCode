#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
ll quick(ll a,ll b,ll c){    //快速幂 
   ll ans=1;  
   a=a%c;  
   while(b!=0)  
   {  
       if(b&1) ans=(ans*a)%c;  
       b>>=1;  
       a=(a*a)%c;  
   }
   return ans;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		ll m,n,k1,k2;
		cin>>m>>n>>k1>>k2;
		ll len=k2-k1;
		m=m*quick(10,k1-1,n)%n;
		rep(i,0,len+1){
			cout<<m*10/n;
			m=m*10%n; 
		}
		cout<<endl;
	}
}

#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
ll quick(ll a,ll b,ll c){    //¿ìËÙÃÝ 
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
	int t;
	scanf("%d",&t);21
	
	while(t--){
		ll a,n,b;
		scanf("%lld%lld%lld",&a,&n,&b);
		ll ans=quick(a,n,b);
		cout<<ans<<endl;
	}
}




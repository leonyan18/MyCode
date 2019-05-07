#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int getsum(ll n){
	ll ans=0;
	while(n>0){
		ans+=n%10;
		n=n/10;
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
		ll n;
		cin>>n;
		ll ans=0;
		ll temp=n;
		while(temp>0){
			temp=temp/10;
			if(temp!=0)
			ans=ans*10+9;
		}
//		cout<<ans<<endl;
		cout<<getsum(ans)+getsum(n-ans)<<endl;
	}
}




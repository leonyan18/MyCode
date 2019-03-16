#include<bits/stdc++.h>
#include<queue>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int main(){
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	ll t;
	cin>>t;
	while(t--){
		ll x,y,k;
		cin>>x>>y>>k;
		ll minv=min(x,y);
		ll les=x+y-2*minv;
		if(les+minv>k){
			cout<<-1<<endl;
		} else{
			ll ans;
			if(les*2+minv>=k)
				ans=k-les;
			else{
				if((k-les*2-minv)%2==0)
				ans=k-les;
				else{
					ans=-1;
				} 
			}
			cout<<ans<<endl;
		}
	}
}




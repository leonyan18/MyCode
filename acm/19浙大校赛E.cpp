#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1005;
ll a[maxn];
ll b[maxn];
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
		clr(a);
		clr(b);
		ll n;
		cin>>n;
		rep(i,0,n){
			cin>>a[i];
		}
		rep(i,0,n){
			cin>>b[i];
		}
		ll now=0;
		int flag=1;
		per(i,0,n){
			ll need=a[i]-b[i];
			if(need>=0&&now<need){
				flag=0;
				break;
			}
			now-=need;
		}
		if(flag){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	} 
}




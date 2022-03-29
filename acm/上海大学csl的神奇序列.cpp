#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
const int mod=998244353;
ll a[maxn];
int main(){
	//±¾µØ²âÊÔ
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int w,q;
	cin>>w>>q;
	a[1]=w;
	rep(i,2,1000005){
		a[i]=a[i-1]*(i*2-1)%mod;
	}
	while(q--){
		int pos;
		cin>>pos;
		cout<<a[pos]<<endl;
	}
}




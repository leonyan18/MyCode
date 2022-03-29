#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
ll a[maxn];
int main(){
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	ll maxv=0;
	rep(i,1,n+1){
		cin>>a[i];
		maxv=max(maxv,a[i]);
		a[n+i]=a[i];
	}
	ll sum=0;
	ll len=0;
	rep(i,1,2*n+1){
		sum+=a[i];
		len++;
		if(len<=n)
			maxv=max(maxv,sum);
		if(sum<0){
			sum=0;
			len=0;
		}
	}
	cout<<maxv<<endl;
}

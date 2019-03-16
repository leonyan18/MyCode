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
	int n;
	cin>>n;
	ll maxv=0;
	rep(i,0,n){
		cin>>a[i];
		maxv=max(maxv,a[i]);
		a[n+i]=a[i];
	}
	ll sum=0;
	ll len=0;
	rep(i,0,2*n){
		sum+=a[i];
		maxv=max(maxv,sum);
		len++;
		if(sum<0){
			sum=0;
			len=0;
		} 
		if(len==n){
			sum-=a[i-len+1];
			len--;
		}
	}
	cout<<maxv<<endl;
}

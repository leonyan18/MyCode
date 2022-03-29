#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
double a[maxn];
ll n,m;
bool check(double c){
	ll sum=0;
	rep(i,0,n){
		sum+=(int)a[i]/c;
		if(sum>=m){
			return true;
		}
	}
	if(sum>=m){
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	cin>>n>>m;
	rep(i,0,n){
		cin>>a[i];
	}
	sort(a,a+n);
	double l=0;
	double r=a[n-1];
	double mid=0;
	double ans=0;
	while(abs(r - l) > 1e-4){
		mid=(l+r)/2.0;
		if(check(mid)){
			l=mid;
			ans=max(ans,mid);
		}else{
			r=mid;
		}
	}
	printf("%.2lf\n",ans);
}




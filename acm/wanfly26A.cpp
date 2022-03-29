#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e3+5;
double x[maxn];
double y[maxn];
int main(){
	//±¾µØ²âÊÔ
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	rep(i,0,n){
		scanf("%lf%lf",&x[i],y[i]);
	}
	int ans=-1;
	rep(i,0,n){
		double dis=0.0;
		int flag=1;
		rep(j,0,n){
			if(i==j)
			continue;
			double temp=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			if(dis==0){
				dis=temp;
			}
			if(dis!=temp){
				flag=0;
			}
		}
		if(flag){
			ans=i+1;
		}
	}
	cout<<ans<<endl;
}




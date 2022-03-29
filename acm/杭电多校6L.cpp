#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	int ans;
	cin>>t;
	while(t--){
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		x=x*(-1);
		double h=x*1.0/a*b;
		if(h>y)
		ans=0;
		else if(h==y){
			ans=1;
		}
		else {
			double t1=sqrt(2*(y-h)/9.8);
			double t2=sqrt(2*((a*a+b*b)*h/b/b+(y-h))/9.8)-t1;
			ans=t2/t1/2+1;
		}
		cout<<ans<<endl;
	} 
}



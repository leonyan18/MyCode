#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int a[15];
int b[15];
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
		double n,m,y;
		cin>>n>>m>>y;
		double sum1=0;
		rep(i,0,n){
			cin>>a[i];
			sum1+=a[i];
		}
		sum1=sum1/n;
		double sum2=0;
		rep(i,0,m){
			cin>>b[i];
			sum2+=b[i];
		}
		sum2=sum2/m;
		double ans=0;
		double base=1;
		double time=sum1;
		rep(i,0,200000){
			double temp1=base*n*1.0/(n+m);
			if(temp1<1e-9)
				break;
			ans+=temp1*time;
			base=base-temp1;
			time+=sum2;
		}
		if(ans<=y&&sum1<=y){
			cout<<"Go"<<endl;
		}else{
			cout<<"Wait"<<endl;
		}
	}
}


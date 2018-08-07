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
	int n,p2,p3;
	int ans=0;
	cin>>n>>p2>>p3;
	if(p2*3<=p3*2){
		ans=(n-n%2)/2*p2;
		if(n%2){
			if(n>2)
			ans=min(ans+p2,ans+p3-p2);
			else
			ans=ans+p2;
		}
	}
	else{
		ans=(n-n%3)/3*p3;
		if(n%3==1){
			if(ans>3)
			ans=min(ans+p2,min(ans-p3+2*p2,ans+p3));
			else{
				ans=min(ans+p2,ans+p3);
			}
		}
		if(n%3==2){
			ans=min(ans+p2,ans+p3);
		}
	}
	cout<<ans<<endl;
}



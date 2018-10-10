#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e4+5;
const int mod=2333;
int f[maxn*2];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n;
	cin>>n;
	clr(f);
	f[0]=1;
	rep(i,1,n+1){
		char c;
		cin>>c;
		if(c==')'){
			rep(j,0,i){
				f[j]+=f[j+1];
			}
		}
		else{
			per(j,1,i+1){
				f[j]+=f[j-1];
			}
		}
	}
	cout<<f[0]<<endl;
	
}	




#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int f[100];
int sg[1005];
int len=0;
int vis[1005];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	f[1]=f[2]=1;
	rep(i,3,100){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>1000){
			len=i;
			break;
		}
	}
	sg[0]=0;
	rep(i,1,1005){
		clr(vis);
		rep(j,2,len){
			if(i<f[j]){
				break;
			}
			vis[sg[i-f[j]]]=1;
		}
		rep(j,0,1005){
			if(!vis[j]){
				sg[i]=j;
				break;
			}
		}
	}
	int n,m,p;
	while(cin>>n>>m>>p){
		if(n+m+p==0){
			break;
		}
		int ans=sg[n]^sg[m]^sg[p];
		if(ans){
			cout<<"Fibo"<<endl;
		}else{
			cout<<"Nacci"<<endl;
		}
	}
}


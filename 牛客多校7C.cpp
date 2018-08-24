#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e6+5;
char s[maxn];
bool a[20][maxn];
int n;
int ans;
void dfs(int pos,int len,int op){
	int k=len>>1;
	int sum0=0;
	if(op==1)
	rep(i,1,k+1){
			a[pos+1][i]=a[pos][i<<1]|a[pos][i<<1-1];
			if(a[pos+1][i]==0){
				sum0++;
			}
	}
	if(op==2)
	rep(i,1,k+1){
			a[pos+1][i]=a[pos][i<<1]&a[pos][i<<1-1];
			if(a[pos+1][i]==0){
				sum0++;
			}
	}
	if(op==3)
	rep(i,1,k+1){
			a[pos+1][i]=a[pos][i<<1]^a[pos][i<<1-1];
			if(a[pos+1][i]==0){
				sum0++;
			}
	}
	if(len==2){
		ans+=a[pos+1][1];
		return ;
	}
	if(sum0==k)
	return;
	dfs(pos+1,k,1);
	dfs(pos+1,k,2);
	dfs(pos+1,k,3);
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	cin>>n;
	n=pow(2,n);
	cin>>s;
	rep(i,1,n+1){
		a[0][i]=s[i-1]-'0';
	}
	ans=0;
	dfs(0,n,1);
	dfs(0,n,2);
	dfs(0,n,3); 
	cout<<ans;
	
}



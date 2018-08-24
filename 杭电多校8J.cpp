#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
int a[maxn];
int b[maxn];
int c[maxn]; 
int presum[maxn];
int lastsum[maxn];
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
		int n,m;
		cin>>n>>m;
		a[0]=0;
		b[0]=0;
		rep(i,1,n+1){
			cin>>a[i];
		}
		int maxv=a[0];
		rep(i,1,n+1){
			maxv=max(maxv,a[i]);
			b[i]=maxv;
		}
		int sum=1;
		presum[1]=1;
		rep(i,2,n+1){
			if(a[i]==b[i]&&b[i-1]!=b[i]){
				sum++;
			}
			presum[i]=sum;
		}
		sum=0;
		per(i,2,n+1){
			if(a[i]==b[i]&&b[i-1]!=b[i]){
				sum++;
			}
			lastsum[i]=sum;
		}
		lastsum[1]+=sum+1;
		while(m--){
			int pos,val;
			cin>>pos>>val;
			int ans=presum[pos];
			if(val>b[pos]){
				if(a[pos]!=b[pos])
				ans++;
				int nextpos=upper_bound(b+pos,b+n,val)-b;
				if(nextpos!=n)
				ans+=lastsum[nextpos];
			}
			else{
				if(a[pos]!=b[pos]||val==b[pos])
					ans+=lastsum[pos];
				else if(a[pos-1]==b[pos]){
					ans+=lastsum[pos];
				}
				else{
					if(b[pos-1]>val)
						
				} 
				
			}
		}
	}
}



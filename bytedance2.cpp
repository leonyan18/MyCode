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
int flag[maxn];
int ans[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		clr(flag);
		clr(b);
		clr(ans);
		int len=0;
		rep(i,0,n){
			scanf("%d",&a[i]);
			if(flag[a[i]]==0){
				b[len++]=a[i];
			}
			flag[a[i]]=1;
		}
		sort(b,b+len);
		rep(i,0,n){
			int pos=lower_bound(b,b+len,a[i])-b;
			ans[i]=pos+1;
		}
		int flag=1;
		while(flag){
			flag=0;
			rep(i,0,n){
				int now=i;
				int pre=i-1;
				if(pre<0){
					pre=pre+n;
				}
				int next=i+1;
				if(next>=n){
					next-=n;
				}
				if(a[now]<=a[pre]&&a[now]>a[next]){
					if(ans[now]!=ans[next]+1){
						ans[now]=ans[next]+1;
						flag=1;
					}
				}else if(a[now]<=a[next]&&a[now]>a[pre]){
					if(ans[now]!=ans[pre]+1){
						ans[now]=ans[pre]+1;
						flag=1;
					}
				}else if(a[now]<=a[next]&&a[now]<=a[pre]){
					if(ans[now]!=1){
						ans[now]=1;
						flag=1;
					}
				}else if(a[now]>a[next]&&a[now]>a[pre]){
					if(ans[now]!=max(ans[pre],ans[next])+1){
						ans[now]=max(ans[pre],ans[next])+1;
						flag=1;
					}
				}
			}
		}
		ll sum=0;
		rep(i,0,n){
			sum+=ans[i];
		}
		printf("%lld\n",sum);
	}
}
/*
2
5
5 4 3 2 1
2
1 2
*/




#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
ll a[maxn];
int main(){
	//±¾µØ²âÊÔ
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int t;
	scanf("%d",&t);
	while(t--){
		clr(a);
		int n,k;
		scanf("%d%d",&n,&k);
		int temp=0;
		rep(i,0,n){
			scanf("%lld",&a[temp]);
			if(a[temp]!=0){
				temp++;
			}
		}
		n=temp;
		sort(a,a+n);
		int sum=lower_bound(a,a+n,0)-a;
		ll ans=0;
		if(sum>=k){
			ans+=a[0];
		}
		if(n-sum>=k){
			ans-=a[n-1];
		}
		int pre=0;
		int next=n-1;
		rep(i,0,sum){
			if(i+k-1<sum&&a[i+k-1]<0){
				ans-=2*a[i];
				i+=k-1;
				pre=i+1;
			}else{
				break;
			}
			
		}
		per(i,sum,n){
			if(i-k+1>=sum&&a[i-k+1]>0){
				ans+=2*a[i];
				i-=k-1;
				next=i-1;
			}else{
				break;
			}
		}
		if(a[pre]*a[next]<0){
			ans+=abs(abs(a[next])+abs(a[pre]))*2;
		}else{
			ans+=max(abs(a[next]),abs(a[pre]))*2;
		}
//		cout<<pre<<" "<<next<<endl;
		printf("%lld\n",ans);
	}
}




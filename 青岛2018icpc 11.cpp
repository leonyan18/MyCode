#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int sum[30];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		int n;
		clr(sum);
		cin>>n;
		rep(i,0,n){
			int temp;
			cin>>temp;
			int time=0;
			int pos=0;
			while(temp>0){
				if(temp%2==1){
					pos=time;
				}
				time++;
				temp=temp>>1;
			}
			sum[pos]++;
		}
		int ans=0;
		rep(i,0,30){
			ans=max(ans,sum[i]);
		}
		cout<<ans<<endl;
	} 
}




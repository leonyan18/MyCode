#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=20+3;
int num[maxn][2];
vector<int> pre[maxn];
ll dp[1<<maxn];
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
	clr(dp);
	rep(i,1,n+1){
		int len=0;
		cin>>num[i][0]>>num[i][1]>>len;
		rep(j,0,len){
			int temp;
			cin>>temp;
			pre[i].push_back(temp);
		}
	}
	rep(i,0,1<<n){
		int count=0;
		rep(j,0,25){
			if((i>>j)%2==1){
				count++;
			}
		}
		if(count==3){
			count=3;
		}
		rep(j,1,n+1){
			int flag=1;
			if((i>>j-1)%2==0)
				continue;
			rep(k,0,pre[j].size()){
				int temp=pre[j][k];
				if((i>>temp-1)%2==0){
					flag=0;
					break; 
				}		
			}
			if(flag){
				dp[j]=max(dp[j],dp[j-(1<<j-1)]+count+1*num[j][0]+num[j][1]);
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
}




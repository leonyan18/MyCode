#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
char num[2][maxn];
ll dp[2][maxn];
ll presum[2][maxn];
int main(){
	//±¾µØ²âÊÔ
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		clr(dp);
		clr(presum);
		cin>>num[0];
		int len=strlen(num[0]);
		rep(i,0,len){
			if(num[0][i]=='1')
				num[1][i]='0';
			else
				num[1][i]='1';
		}
		int time=0;
		rep(i,0,len){
			int pos=dp[0][i]%2;
			if(num[pos][i]=='1')
				time++;
			else
				time+=2;
			dp[0][i+1]=time;
		}
		time=0;
		rep(i,0,len){
			int pos=(time+1)%2;
			if(num[pos][i]=='1')
				time++;
			else
				time+=2;
			dp[1][i+1]=time;
		}
		rep(i,1,len+1){
			presum[0][i]=presum[0][i-1]+dp[0][i];
			presum[1][i]=presum[1][i-1]+dp[1][i];
		}
		ll sum=0;
		int pos=0;
		rep(i,1,len+1){
			if(dp[0][i-1]%2==0)
				sum+=presum[0][len]-presum[0][i-1]-dp[0][i]*();
			else
				sum+=presum[1][len]-presum[1][i-1];
		}
		cout<<sum<<endl;
	}
}




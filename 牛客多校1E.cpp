#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define erep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define eper(i,a,n) for (int i=n;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int mod = 1e9 + 7;
int dp[100004][15]; //长度为i 结尾数字j的方案个数 
int a[100004];//数组的值 
int sum[100004]; //长度为i的方案个数 
int dp2[100004][15];//到第i个数字 去掉j个数字的方案个数 
int main(){
	int prev[15];// 值对应的前一个位置 
	int prep[15];//当前位置的前一个相同的 
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,m,k;
	while(cin>>n>>m>>k){
		clr(a);
		clr(dp);
		clr(sum);
		clr(prep);
		clr(prev);
		erep(i,1,n){
			cin>>a[i];
			prep[i]=prev[a[i]];
			prev[a[i]]=i;
		}
		/*
		way1  
		*/
		sum[0]=1;
		erep(i,1,n){
			for(int j=i;j>=i-m-1&&j>=1;j--){
				sum[j]+=(sum[j-1]-dp[j][a[i]]+mod)%mod;//多了一种结尾数字为a[i]的情况，但是重复了dp[j][a[i]]次
				//当前面出现过a[i]时 
				sum[j]%=mod;
				dp[j][a[i]]=sum[j-1]%mod;//末尾数字为a[i]长度为j的个数是长度为j-1的序列个数 
			}
		}
		cout<<sum[n-m]%mod<<endl;
		/*
		way2 
		*/
		dp2[0][0]=1;
		erep(i,1,n){
			int d=i-prep[i];
			dp2[i][0]=1;
			for(int j=1;j<=m&&j<=i;j++){
				dp2[i][j]=dp2[i-1][j-1]+dp2[i-1][j];
				if(prep[i]&&d-j>=0)dp2[i][j]-=dp2[prep[i]-1][j-d];
				dp2[i][j]+=mod;
				dp2[i][j]%=mod;
			}
		}
		cout<<dp2[n][m]<<endl;
	}
}




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
int dp[100004][15]; //����Ϊi ��β����j�ķ������� 
int a[100004];//�����ֵ 
int sum[100004]; //����Ϊi�ķ������� 
int dp2[100004][15];//����i������ ȥ��j�����ֵķ������� 
int main(){
	int prev[15];// ֵ��Ӧ��ǰһ��λ�� 
	int prep[15];//��ǰλ�õ�ǰһ����ͬ�� 
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
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
				sum[j]+=(sum[j-1]-dp[j][a[i]]+mod)%mod;//����һ�ֽ�β����Ϊa[i]������������ظ���dp[j][a[i]]��
				//��ǰ����ֹ�a[i]ʱ 
				sum[j]%=mod;
				dp[j][a[i]]=sum[j-1]%mod;//ĩβ����Ϊa[i]����Ϊj�ĸ����ǳ���Ϊj-1�����и��� 
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




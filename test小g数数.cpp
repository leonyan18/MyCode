#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=505;
int sum[maxn][maxn];//��jλ��iС�����ĺ� 
int sums[maxn][maxn];
int a[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>a[i];
	}
	rep(i,1,n+1){
		int temp=0;
		int temp1=0;
		rep(j,1,n+1){
			if(i<a[j]){
				temp++;
			}
			if(i>a[j]){
				temp1++;
			}
			sum[i][j]=temp;
			sums[i][j]=temp1;
		}
	}
	ll ans=0;
	rep(i,2,n+1){
		rep(j,i+1,n+1){
			int c=a[j];
			int b=a[i];
			int lb=sum[b][n]-sum[b][j];
			int sc=sums[c][i-1];
			ans+=sc*lb;
		}
	}
	cout<<ans<<endl;
}




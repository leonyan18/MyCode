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
ll sum[maxn];
ll sum2[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		rep(i,1,n+1){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
			sum2[i]=sum2[i-1]+a[i]*a[i];
		}
		ll ans=0;
		per(i,1,n+1){
			ans+=(i-1)*a[i]*a[i]+sum2[i-1]-2*a[i]*sum[i-1];
		}
		cout<<ans<<endl;
	}
}




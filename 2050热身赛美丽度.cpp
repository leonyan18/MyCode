#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
const int mod=1e9+7;
int ans[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	rep(i,1,1000005){
		ans[i]=ans[i-1]+i;
		ans[i]%=mod; 
	}
	int n;
	cin>>n;
	ll sum=0;
	rep(i,0,n){
		ll val;
		cin>>val;
		sum+=ans[n-i]*val%mod*(i+1)%mod;
	}
	cout<<sum<<endl;
}

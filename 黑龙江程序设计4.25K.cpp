#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int getsum(ll n){
	ll ans=0;
	while(n>0){
		ans+=n%10;
		n=n/10;
	}
	return ans;
}
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
		ll n;
		cin>>n;
		ll ans=0;
		ll temp=n;
		while(temp>0){
			temp=temp/10;
			if(temp!=0)
			ans=ans*10+9;
		}
//		cout<<ans<<endl;
		cout<<getsum(ans)+getsum(n-ans)<<endl;
	}
}




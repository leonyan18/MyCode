#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
ll a[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int a,b,c;
	cin>>a>>b>>c;
	int p1,p2,q1,q2;
	cin>>p1>>p2>>q1>>q2;
	ll ans=1e15;
	rep(i,-1*1e6,1e6){
		if((a*i-c)%b==0){
			ll x=i;
			ll y=-1*(a*i-c)/b;
			ll temp=p2*x*x+p1*x+q2*y*y+q1*y;
			ans=min(temp,ans);
			if(temp==2)
			cout<<x<<" "<<y<<endl;
		}
	}
	if(ans!=1e15)
	cout<<ans<<endl;
	else
	cout<<"Kuon"<<endl;
}




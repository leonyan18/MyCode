#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e4+5;
bool isprime[maxn];
ll sum[maxn];
ll	a[maxn];
ll sum1[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	ll n,p;
	cin>>n>>p;
	clr(isprime);
	isprime[1]=0;
	int len=0;
	rep(i,2,p+1){
		if(isprime[i]==0){
			if(p%i==0){
				a[len]=i;
				ll temp=p;
				while(temp%i==0&&temp!=0){
					temp=temp/i;
					sum1[len]++;
				}
				len++;
			}
			for(int j=i;j*i<=p;j++){
				isprime[i*j]=1;
			}
		}
	}
	rep(i,0,len){
		ll base=a[i];
		sum[i]=0;
		while(n/base){
			sum[i]+=n/base;
			base=base*a[i];
		}
	}
	ll ans=1e18;
	rep(i,0,len){
		ans=min(sum[i]/sum1[i],ans);
	}
	cout<<ans<<endl; 
}




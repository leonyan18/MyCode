#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
const int mod=998244353;
long long quick(long long a,long long b){    //������ 
    long long ans=1;  
    a=a%mod;  
    while(b!=0)  
    {  
        if(b&1) ans=(ans*a)%mod;  
        b>>=1;  
        a=(a*a)%mod;  
    }  
    return ans;  
} 
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int t;
	cout<<(4*quick(3,mod-2))%mod<<endl;
	cin>>t;
	while(t--){
		int x,q;
		cin>>x>>q;
		ll ans=quick((q-x),mod-2);
		cout<<ans<<endl;
	}
}




#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
#define mod 1000000007
ll a[105],f[105];//f��2�ļ����� a��i+1��һ�γ���֮ǰ�ĸ��� 
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	ll T;
    scanf("%lld",&T);
    a[0]=f[0]=1;
    for(ll i=1;i<=62;i++)a[i]=a[i-1]*2+1,f[i]=f[i-1]*2;
    ll inv=(mod+1)/2;
    while(T--)
    {
        ll pos=0,n,m,ans=0;
        scanf("%lld",&n);
        m=n;
        for(ll i=62;i>=0;i--)
            if(m-a[i]>=0)
                m-=a[i],pos=pos+(1ll<<i);//�����λ������Ǹ����ظ�����û�н�����posȡ��ʼ֮ǰ��λ�� 
        pos+=(m>0);
        ll now=pos-1,num=0;
        for(ll i=1;f[i-1]<=now;i++)//�Ȳ�������� 
        {//e�����һ������λ�� step�ǵڼ�����  s�ǵ�һ�� 
            ll s=f[i-1],step=(now-s)/f[i]+1,e=(step-1)*f[i]+s; 
            ll haha=(s+e)%mod*(step%mod)%mod*inv%mod;//sn�Ȳ����еĺ� invȡ��Ԫ 
            ans=(ans+haha*i%mod)%mod;//i�ظ�����
            num+=step*i;//num�Ǽ�¼�ĸ���
        }
//        cout<<"pos  "<<pos<<endl; 
        ans=(ans+1+(n-num-1)%mod*(pos%mod)%mod)%mod;//(n-num-1)ȱ�ٵĸ��� ��Ϊ���˸�1 
        printf("%lld\n",ans);
    }
}





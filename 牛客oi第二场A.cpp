#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int t;
	cin>>t;
	while(t--){
		int a,b;
		int counta,countb,countab;
		counta=countb=countab=0;
		cin>>a>>b;
		rep(i,1,max(a,b)+1){
			if(a%i==0)
				counta++;
			if(b%i==0){
				countb++;
			}
			if(a%i==0&&b%i==0){
				countab++;
			}
		}
		ll ans;
		if(countab<=1)
			ans=counta*countb;
		else{
			ans=counta*countb-countab*(countab-1)/2;
		}
		cout<<ans<<endl;
	} 
}




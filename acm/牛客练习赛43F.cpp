#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int a[10]={2,3,5,7,11,13,17,19}; 
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
		ll k,q,n,m;
		cin>>k>>q>>n>>m;
		if(k==0){
			cout<<"QAQ"<<endl;
			continue;
		}
		ll sum=n/2;
		rep(i,1,8){
			if(a[i]>m)
				break;
			sum=sum/a[i];
		}
		cout<<q<<" "<<sum<<endl;
		q=q-sum;
		if(q<=0){
			cout<<"Yes"<<endl;
		}else{
			if(k<=q){
				cout<<"QAQ"<<endl;
			}else{
				cout<<"Yes"<<endl;
			}
		}
	} 
}




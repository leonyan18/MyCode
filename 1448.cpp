#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=200005;
int a[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int n,m;
	cin>>n>>m;
	rep(i,0,n)
		cin>>a[i];
	while(m--){
		string s;
		cin>>s;
		if(s[0]=='S'){
			int l,r;
			cin>>l>>r;
			ll sum=0;
			rep(i,l-1,r){
				sum+=a[i];
			}
			cout<<sum<<endl;
		}else{
			int l,r,x;
			cin>>l>>r>>x;
			rep(i,l-1,r){
				a[i]=a[i]|x;
			}
		}
	}
	
}

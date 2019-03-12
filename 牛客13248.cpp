#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int sum1[4];
int sum2[4];
char a[maxn];
char b[maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		clr(sum1);
		clr(sum2);
		cin>>a;
		cin>>b;
		int alen=strlen(a);
		int blen=strlen(b);
		rep(i,0,alen){
			if(a[i]=='A'){
				sum1[0]++;
			}
			if(a[i]=='G'){
				sum1[1]++;
			}
			if(a[i]=='C'){
				sum1[2]++;
			}
			if(a[i]=='T'){
				sum1[3]++;
			}
		}
		rep(i,0,blen){
			if(b[i]=='A'){
				sum2[0]++;
			}
			if(b[i]=='G'){
				sum2[1]++;
			}
			if(b[i]=='C'){
				sum2[2]++;
			}
			if(b[i]=='T'){
				sum2[3]++;
			}
		}
		ll ans=0;
		rep(i,0,4)
		ans+=min(sum1[i],sum2[i]);
		cout<<ans<<endl;
	}
}




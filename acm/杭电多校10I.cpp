#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
ll Gcd(ll a, ll b)//gcd 
{
    while(b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
//	cin>>t;
	t=60;
	int n=1;
	int sum=0;
	while(t--){
//		cin>>n;
		sum=0;
		rep(i,1,n+1){
			rep(j,1,i-1){
				if(Gcd(i+j,i-j)==1){
					sum++;
				}
			}
		}
		cout<<n<<" "<<sum<<endl;
//		cout<<sum<<endl;
		n++;
	} 
}




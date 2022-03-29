#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef  long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
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
ll lcm(ll a, ll b){    //求最小公倍数
    return a * b / Gcd(a, b);  
//   return a / gcd(a, b) * b;  
}  
unsigned x,y,z;
unsigned tang(){
	unsigned t;
	x^=x<<16;
	x^=x>>5;
	x^=x<<1;
	t=x;
	x=y;
	y=z;
	z=t^x^y;
	return z;
}
unsigned a[10000005];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
    freopen("C://Users//yan//Desktop//out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	rep(ca,1,t+1){
		ll ans=0;
//		cout<<"Case #"<<ca<<": ";
		int n;
		cin>>n>>x>>y>>z;
		rep(i,0,n){
			a[i]=tang();
			cout<<a[i]<<" " ;
		}
		cout<<endl;
		rep(i,1,n){
//			ll temp=(ll)a[i-1]*(ll)a[i];
//			ans=max(ans,temp);
			cout<<Gcd(a[i-1],a[i])<<" ";
		}
		cout<<endl;
		sort(a,a+n);
		cout<<endl;
		rep(i,0,n){
//			a[i]=tang();
			cout<<a[i]<<" " ;
		}
		cout<<endl;
		rep(i,1,n){
//			ll temp=(ll)a[i-1]*(ll)a[i];
//			ans=max(ans,temp);
			cout<<Gcd(a[i-1],a[i])<<" ";
		}

		cout<<endl;
	} 
}



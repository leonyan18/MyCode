#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
struct node{
	ll pos;
	ll h;
	bool operator<(const node b)const{ //定义比较方式，这一步很重要
        if(h==b.h){
			return pos<b.pos;
		}
		return  h<b.h;
    }
};
node a1[maxn];
node a2[maxn];
node gt[maxn];
node gs[maxn];
node bt[maxn];
node bs[maxn];
int p1[maxn];
int p2[maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int t;
	scanf("%d",&t);
	while(t--){
		clr(a1);
		clr(a2); 
		clr(gs);
		clr(gt); 
		clr(bs);
		clr(bt);
		clr(p1);
		clr(p2);
		int n,m;
		cin>>n>>m;
		rep(i,0,n){
			scanf("%lld",&a1[i].h);
			a1[i].pos=i;
		}
		rep(i,0,m){
			scanf("%lld",&a2[i].h);
			a2[i].pos=i;
		}
		sort(a1,a1+n);
		sort(a2,a2+m);
		rep(i,0,n){
			scanf("%lld",&p1[i]);
//			cout<<p1[i];
		}
//		cout<<endl;
		rep(i,0,m){
			scanf("%lld",&p2[i]);
//			cout<<p1[i];
		}
//		cout<<endl;
		ll lengt=0;
		ll lengs=0;
		rep(i,0,m){
			if(p2[a2[i].pos]==1)
				gt[lengt++]=a2[i];
			else{
				gs[lengs++]=a2[i];
			}
		}
		ll lenbt=0;
		ll lenbs=0;
		rep(i,0,n){
			if(p1[a1[i].pos]==1)
				bt[lenbt++]=a1[i];
			else{
				bs[lenbs++]=a1[i];
			}
		}
		ll sum=0;
		ll bp=0;
		ll gp=0;
		while(bp<lenbt&&gp<lengs){
			if(bt[bp].h>gs[gp].h){//男生比他高，下个男生也比他高，所以女生下一个 
				gp++;
			}else{
//				cout<<bt[bp].pos<<" "<<gs[gp].pos<<endl;
				sum++;
				bp++;
				gp++;
			}
		}
		bp=0;
		gp=0;
		while(bp<lenbs&&gp<lengt){
			if(bs[bp].h<gt[gp].h){//女生比他高，下个女生还是比他高 
				bp++;
			}else{
//				cout<<bs[bp].pos<<" "<<gt[gp].pos<<endl;
				sum++;
				bp++;
				gp++;
			}
		}
		printf("%lld\n",sum);
	}
}




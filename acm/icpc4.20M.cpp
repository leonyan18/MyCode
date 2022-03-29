#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
int mm[27][maxn];
int last[maxn][27];
int lp[27];
int mml[27];
char s[maxn];
char T[maxn];
int main(){
	//±æµÿ≤‚ ‘
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	scanf("%s",s);
	int n;
	scanf("%d",&n);
	int slen=strlen(s);
	rep(j,0,27){
		lp[j]=slen;
	}
	per(i,0,slen){
		int now=s[i]-'a';
		lp[now]=i;
		rep(j,0,27){
			last[i][j]=lp[j];
		}
	}
	rep(i,0,n){
		scanf("%s",T);
		int len=strlen(T);
		int flag=1;
		int pos=0;
		rep(j,0,len){
			int now=T[j]-'a';
			int next=last[pos][now];
			if(next==slen||next<pos){
				flag=0;
				break;
			}
			pos=next+1;
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}

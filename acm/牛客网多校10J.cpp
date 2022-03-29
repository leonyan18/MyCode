#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int pos[27][maxn];
int len[27];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
//    freopen("C://Users//yan//Desktop//out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		clr(pos);
		clr(len);
		int n;
		cin>>n;
		string a;
		cin>>a;
		string ans=a;
		rep(i,0,a.length()){
			int temp=a[i]-'a';
			pos[temp][len[temp]]=i;
			len[temp]++;
		}
		rep(i,1,n){
			cin>>a;
			int slen=a.length();
			int nowpos=-1;
			int oklen=0;
			rep(j,0,slen){
				int temp=a[j]-'a';
				int nextpos=upper_bound(pos[temp],pos[temp]+len[temp],nowpos)-pos[temp];
				if(nextpos==len[temp]){
					break;
				}
				nowpos=pos[temp][nextpos];	
				oklen++;				
			}
			rep(j,oklen,slen){
				ans+=a[j];
				int temp=a[j]-'a';
				pos[temp][len[temp]]=ans.length()-1;
				len[temp]++;
			}
		}
		cout<<ans<<endl;
	}
}




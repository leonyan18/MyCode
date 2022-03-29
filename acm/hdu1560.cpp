#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
char a[10][10];
char b[]="AGCTAGCTAGCTAGCTAGCT";
int n;
char ansstr[100];
int test(int len){
	int sum=0; 
	rep(i,0,n){
		int pos1=0;
		int pos2=0;
		while(pos1<len&&pos2<strlen(a[i])){
			if(b[pos1]==a[i][pos2]){
				sum++;
				pos1++;
				pos2++;
			}else{
				pos1++;
			}
		}
	}
	return sum;
}
int main(){
	//±¾µØ²âÊÔ
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		int sum=0;
		int minlen=20;
		int ans=20;
		rep(i,0,n){
			scanf("%s",a[i]);
			int temp=strlen(a[i]);
			minlen=min(minlen,temp);
			sum+=temp;
		}
		rep(i,0,1<<20){
			int temp=i;
			int len=0;
			rep(i,0,20){
				if(temp&1){
					ansstr[len]=b[i];
					len++;
				}
				temp>>1;
			}
			if(len<minlen||len>ans)
				continue;
			if(test(len)==sum){
				ans=len;
			}	
		}
		int temp=1<<20;
		cout<<temp<<endl;
		cout<<ans<<endl;		
	}
}




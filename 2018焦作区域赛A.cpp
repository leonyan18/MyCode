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
	int t;
	scanf("%d",&t);
    char a[15];
	while(t--){
		scanf("%s",a);
		int len =strlen(a);
		int flag=0;
		
		if(len==6){
			rep(i,0,6){
				if(a[0]-'A'>=0&&a[0]-'A'<=25)
					a[0]=a[0]-'A'+'a';
			}
			if(a[0]=='j'&&a[1]=='e'&&a[2]=='s'&&a[3]=='s'&&a[4]=='i'&&a[5]=='e'){
				flag=1;
			}
		}
		if(flag==1)
			cout<<"Good guy!"<<endl;
		else
			cout<<"Dare you say that again?"<<endl;
	} 
}




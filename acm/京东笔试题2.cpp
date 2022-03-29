#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
string a[15]; 
string b;
int nt[maxn];
int pos[15];
int isok[15];
void kmp_next()
{
	nt[0]=0;
    for(int i=1,j=0,m=b.length();i<m;i++)
    {
        while(j&&b[i]!=b[j])j=nt[j-1];
        if(b[i]==b[j])j++;
        nt[i]=j;
    }
}
bool compare(string a,string b){
	return a.length()<b.length();
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}
	cin>>b;
	kmp_next();
	sort(a,a+n,compare);
	clr(isok);
	int len=b.length();
	rep(i,0,len){
		int flag=0;
		rep(j,0,n){
			int now=pos[j];
			if(a[j][now]==b[i]){
				pos[j]++;
				if(pos[j]==a[j].length()){
					isok[j]++;
					pos[j]=0;
					flag=1;
//					cout<<a[j]<<endl;
					break; 
				}
			}else{
				rep(k,pos[j]+1,i+1){
					rep(q,0,a[j].length()){
						if(a[j][q]!=b[k]){
							pos[j]=0;
							break;
						}else{
							pos[j]++;
						}
					}
				}
			}
		}
		if(flag){
			clr(pos);
		}
	}
	ll sum=0;
	rep(j,0,n){
		sum+=isok[j];
	}
	cout<<sum<<endl; 
}

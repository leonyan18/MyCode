#include<iostream>
#include<stdio.h>
using namespace std;
int a[100005];
long long b[100005];
int c[100005][2];
int main(){
	int n,m;
	b[0]=0;
	while(cin>>n>>m){
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			b[i]=sum;
		}		
		int op;
		int numb=0;
		for(int i=0;i<m;i++){			
			cin>>op;
			if(op==1){
				int x,y;
				cin>>x>>y;
				c[numb][0]=x;
				c[numb][1]=y;
				numb++;
			}
			else{
				int l,r;
				cin>>l>>r;
				int ans=0;
				for(int j=0;j<numb;j++){
					if(c[j][0]>=l&&c[j][0]<=r){
						ans+=c[j][1];
					}
				}
				ans+=b[r]-b[l-1];
				cout<<ans<<endl;
			}
		}
	}
}

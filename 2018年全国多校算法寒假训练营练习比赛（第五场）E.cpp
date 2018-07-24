#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int map[1005][1005];
int a[1005][1005];
int numb[100005][3];
int main(){
	int n,m;
	
	while(cin>>n>>m){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>map[i][j];
				if(map[i][j]==0){
					a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
				}
				else{
					a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+1;
				}
			}
		}
		int sum=0;
		for(int j=0;j<m;j++){
			int op;
			cin>>op;
			if(op==1){
				cin>>numb[sum][0]>>numb[sum][1];
				if(map[numb[sum][0]][numb[sum][1]]){
					numb[sum][2]=-1;
					map[numb[sum][0]][numb[sum][1]]=0;
				}
				else{
					numb[sum][2]=1;
					map[numb[sum][0]][numb[sum][1]]=1;
				}
				sum++;
			}
			else{
				int x1,y1,y2,x2;
				int ans;
				cin>>x1>>y1>>x2>>y2;
				ans=a[x2][y2]-a[x1-1][y2]-a[x2][y1-1];
				for(int i=0;i<sum;i++){
					if(numb[i][0]<=x2&&numb[i][0]>=x1&&numb[i][1]<=y2&&numb[i][1]>=y1){
						ans+=numb[i][2];
					}
				}
				printf("%d\n",ans);
			}
		}		
	}
}

#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
int pcard[205][20];
int num[205];
int card[21050];
int main(){
	int t;
	scanf("%d",&t);
	int tt=t;
	while(t--){
		cout<<"Case #"<<tt-t<<":"<<endl;
		clr(pcard);
		clr(card);
		clr(num);
		int n,m;
		scanf("%d%d",&n,&m);
		int pos=0;
		rep(i,0,m){
			scanf("%d",&card[i]);
		}
		rep(i,0,n){
			rep(j,0,5){
				if(pos==m){
					break;
				}
				int val=card[pos++];
				if(val<=2)
				val+=13;
				pcard[i][val]++;
				num[i]++;
			}
				
		}
		int cur=0;
		int pre=0;
		int prep=-1;
		while(1){
//			cout<<prep<<" "<<pre<<" "<<pos<<endl;
			if(cur==n)
			cur=0;
			if(pre==0){//����С���� 
				int flag=0;
				rep(i,3,16){
					if(pcard[cur][i]>=1){
						pre=i;
						pcard[cur][i]--;
						num[cur]--;
						prep=cur;
						flag=1;
						break;
					}						
				}
			}else{//���պô��ڻ���2 
				if(cur==prep){//������ �ϴ����Լ������� 
					int temp=cur;
					rep(i,0,n){//������ʼ���� 
						if(pos==m){
							break;
						} 
						if(temp==n)
							temp=0;
						int val=card[pos++];
						if(val<=2)
						val+=13;
						pcard[temp][val]++;
						num[temp]++;
                        temp++;
					}
					rep(i,3,16){//����С���� 
						if(pcard[cur][i]>=1){
							pre=i;
							pcard[cur][i]--;
							num[cur]--;
							prep=cur;
							break;
						}						
					}
				}
				else if(pcard[cur][pre+1]>=1){//���պô���
					pre++;
					pcard[cur][pre]--;
					num[cur]--;
					prep=cur;
				}else if(pcard[cur][15]>=1&&pre!=15){//��2 
					pre=15;
					pcard[cur][15]--;
					num[cur]--;
					prep=cur;
				}					
			}
			if(num[cur]==0)//�����û���� 
			break; 
			cur++;			
		}
		rep(i,0,n){
			ll sum=0;			
			rep(j,3,16){
//				cout<<pcard[i][j]<<" ";
				if(j==14){
					sum+=pcard[i][j];
				}
				else if(j==15){
					sum+=pcard[i][j]*2;
				}
				else{
					sum+=pcard[i][j]*j;
				}
			}			
			if(sum!=0)
			cout<<sum<<endl;
			else
			cout<<"Winner"<<endl;
		}
	}
}




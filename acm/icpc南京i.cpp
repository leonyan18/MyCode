#include<iostream>
 
using namespace std;
const int N=2e7+5;
 
int prime[N];//�洢����������prime[0]��ʾ���������ĸ���
bool vis[N];
int f[N];//���
 
void solve()
{
	f[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
		  prime[++prime[0]]=i;//�洢������� 
		  f[i]=2;//�����Ľ��Ϊ2 
		}
		for(int j=1;j<=prime[0]&&prime[j]*i<N;j++){
			int x=prime[j]*i;
			vis[x]=true;//���xΪ���� 
			if(i%prime[j])//��i=a*b��a��b������ͬ���Ӽ��ɣ���ôf(i)=f(a)*f(b)
			  f[x]=f[prime[j]]*f[i];
			else{//���prime[j]��i����С������ 
				if(i%(prime[j]*prime[j])==0)//���x��ĳ�������Ӹ�������2��f[i]=0 
				  f[x]=0;
				else//���x��ĳ�������Ӹ���Ϊ2�����Ϊȥ��ƽ����Ľ�� 
				  f[x]=f[x/(prime[j]*prime[j])];
				break;//ŷ��ɸ����֤ÿ������ֻ��������С������ɸȥ�����Ҫ���� 
			}
		}
	}
	//ǰ׺�� 
	for(int i=1;i<N;i++)
	  f[i]+=f[i-1];
}
 
int main()
{
	int t,n;
	solve();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
	return 0;
}


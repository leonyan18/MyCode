#include<iostream>
 
using namespace std;
const int N=2e7+5;
 
int prime[N];//存储连续素数，prime[0]表示连续素数的个数
bool vis[N];
int f[N];//结果
 
void solve()
{
	f[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
		  prime[++prime[0]]=i;//存储这个素数 
		  f[i]=2;//素数的结果为2 
		}
		for(int j=1;j<=prime[0]&&prime[j]*i<N;j++){
			int x=prime[j]*i;
			vis[x]=true;//标记x为合数 
			if(i%prime[j])//若i=a*b且a和b不含相同因子即可，那么f(i)=f(a)*f(b)
			  f[x]=f[prime[j]]*f[i];
			else{//如果prime[j]是i的最小质因子 
				if(i%(prime[j]*prime[j])==0)//如果x的某个质因子个数超过2则f[i]=0 
				  f[x]=0;
				else//如果x的某个质因子个数为2，则答案为去掉平方项的结果 
				  f[x]=f[x/(prime[j]*prime[j])];
				break;//欧拉筛法保证每个合数只被它的最小质因子筛去，因此要跳出 
			}
		}
	}
	//前缀和 
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


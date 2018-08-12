#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll isPrime(ll n)
{	//返回1表示判断为质数，0为非质数，在此没有进行输入异常检测
	double n_sqrt;
	if(n==2 || n==3) return 1;
	if(n%6!=1 && n%6!=5) return 0;
	n_sqrt=floor(sqrt((double)n));
	for(ll i=5;i<=n_sqrt;i+=6)
	{
	    if(n%(i)==0 | n%(i+2)==0) return 0;
	}
        return 1;
} 
int main()
{
	int flag;
	flag=isPrime(998244351);
	cout<<flag<<endl;
	return 0;
}

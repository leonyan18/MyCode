#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
const int mod = 1e9 + 7; 
int mynext[maxn];
long long ans[maxn]; 
char S[maxn], T[maxn];
int slen, tlen;  
long long sum = 0; 
void getNext()  
{  
    int j, k;  
    j = 0; k = -1; mynext[0] = -1;  
    while(j < tlen)  
        if(k == -1 || T[j] == T[k])  
            mynext[++j] = ++k; 
        else  
            k = mynext[k];  
}

void kmp()  
{ 
    int i, j = 0;  
    for(int i = 0;i<slen+1;i++)
    {  
        while(j && S[i] != T[j])  
        {
            ans[j]++;
            j = mynext[j];
        }
        if(S[i] == T[j])
        {
            j++;
        }  
        if(j == tlen)  
        {
            ans[j]++;
            j = mynext[j];
        }  
    }
}  

int main()  
{  
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
    int t;  
    cin>>t; 
    while(t--)  
    {  
        sum = 0;
        clr(ans);
        clr(mynext);
        cin>>S;
        cin>>T;
        strrev(S);
        strrev(T);
        slen = strlen(S);  
        tlen = strlen(T);  
		getNext(); 
        kmp();
        per(i,0,tlen+1)
	    {
	        ans[i]+=ans[i+1];
	        ans[i]%=mod;
	        sum=(sum +ans[i]*i%mod)%mod;
	        sum%=mod;
	    }
	    cout<<sum<<endl;
    }  
    return 0;  
}

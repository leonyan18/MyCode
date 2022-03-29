#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
string a[maxn];
string trim(string s)
{

    if( !s.empty() )
    {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
    return s;

}

int main(){
	//±æµÿ≤‚ ‘
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	map<string,set<string> > mmap;
	set<string> keys;
	int n;
	int pos=0;
	cin>>n;
	while(n--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.empty()||s2.empty()){
			continue;
		}
		if(keys.find(s2)==keys.end()){
			set<string> temp;
			mmap[s2]=temp;
			a[pos++]=s2;
			keys.insert(s2);
//			cout<<s1<<s2<<s2.empty()<<endl;
		}
		mmap[s2].insert(s1);
	}
//	set<string>::iterator iter = keys.begin();
//	cout<<keys.size()<<endl;;
	if(pos==0){
        cout<<endl;
		return 0;
	}
	rep(i,0,pos)
	{
		cout<<a[i];
		set<string> temp=mmap[a[i]];
		set<string>::iterator iter2 = temp.begin();
		while(iter2!=temp.end()){
			string s=*iter2;
			cout<<' '<<trim(*iter2);
			iter2++;
		}
		cout<<endl;
	}
	return 0;
}




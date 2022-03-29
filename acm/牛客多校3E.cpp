#include<bits/stdc++.h>
 
using namespace std;
const double PI = acos(-1.0);
typedef long long ll;
#define rep(i, a, n) for (int i=a;i<n;i++)
#define per(i, a, n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF = 0x3f3f3f3f;
char b[1000005];
int Next[1000005];
int n;
namespace io {
    const int L = (1 << 21) + 1;
    char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, st[55];
    int f, tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
 
    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }
 
    inline void putc(char x) {
        *oS++ = x;
        if (oS == oT) flush();
    }
 
    template<class I>
    inline void gi(I &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
        x *= f;
    }
 
    template<class I>
    inline void print(I x) {
        if (!x) putc('0');
        if (x < 0) putc('-'), x = -x;
        while (x) st[++tp] = x % 10 + '0', x /= 10;
        while (tp) putc(st[tp--]);
    }
 
    inline void gs(char *s, int &l) {
        for (c = gc(); c < 'a' || c > 'z'; c = gc());
        for (l = 0; c <= 'z' && c >= 'a'; c = gc()) s[l++] = c;
        s[l] = 0;
    }
 
    inline void ps(const char *s) { for (int i = 0, n = strlen(s); i < n; i++) putc(s[i]); }
 
    struct IOFLUSHER {
        ~IOFLUSHER() { flush(); }
    } _ioflusher_;
};
 
void SetNext()//子串的next数组，如果只看代码的话，很难得出值的确定方法。
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < n) {
        if (j == -1 || b[i] == b[j])//b为模式数组
        {
            i++;
            j++;
            Next[i] = j;
        } else
            j = Next[j];
    }
}
 
int main() {
//    本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	//    freopen("C://Users//yan//Desktop//out.txt","w",stdout);
	#endif
    ios::sync_with_stdio(false);//取消同步
    std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
    io::gs(b, n);
    SetNext();
    int sum = n - Next[n];
    int ssum = n / sum;
    io::print(sum);
    io::putc('\n');
//    cout << sum << endl;
    for (int i = 0; i < sum; i++) {
        io::print(ssum);
//        cout << ssum;
        for (int j = i; j < n; j = j + sum) {
            io::putc(' ');
            io::print(j);
//            cout << " " << j;
        }
//        cout << endl;
        io::putc('\n');
    }
    return 0;
}

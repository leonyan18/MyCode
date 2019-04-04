#include <cstdio>
#include <cstring>

const int maxn = 200;
char s[maxn + 10];
int g[maxn + 10], ans[maxn + 10];
bool vis[maxn + 10];

bool winning(const char* s)
{
    int n = strlen(s);
    for(int i = 0; i < n-2; i++)//�Ѿ����������ڵ�X��������
        if(s[i] == 'X' && s[i+1] == 'X' && s[i+2] == 'X') return false;

    bool no[n+1];
    memset(no, false, sizeof(no));
    for(int i = 0; i < n; i++) if(s[i] == 'X')
    {
        for(int d = -2; d <= 2; d++)
        {
            if(i+d >= 0 && i+d < n)
            {
                if(d != 0 && s[i+d] == 'X') return true;//������X�ڱ˴˵Ľ���������ʤ
                no[i+d] = true;//���ý���
            }
        }
    }

    no[n] = 1;
    int sg = 0;
    for(int i = 0; i < n; i++)
    {
        if(no[i]) continue;
        int cnt = 0;
        while(i < n && !no[i]) { i++; cnt++; }
        sg ^= g[cnt];
    }
    return sg != 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    g[0] = 0;
    g[1] = g[2] = g[3] = 1;
    for(int i = 4; i <= maxn; i++)
    {//��������g
        memset(vis, false, sizeof(vis));
        for(int j = 3; i-j >= 0; j++)
        {
            int v = 0;
            v ^= g[i-j];
            int x = j - 5;
            if(x > 0) v ^= g[x];
            vis[v] = true;

            for(int j = 0; ; j++) if(!vis[j]) { g[i] = j; break; }
        }
    }

    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        if(!winning(s)) { printf("LOSING\n\n"); continue; }

        puts("WINNING");
        int n = strlen(s);
        memset(ans, 0, sizeof(ans));
        int p = 0;
        for(int i = 0; i < n; i++) if(s[i] == '.')
        {
            s[i] = 'X';
            if(!winning(s)) ans[p++] = i+1;//��̱ذ�״̬����������һ���Ĳ���
            s[i] = '.';
        }
        for(int i = 0; i < p; i++)
        {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}

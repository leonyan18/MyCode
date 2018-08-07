#include <bits/stdc++.h>
 
using namespace std;
short a[205][205];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, flag_1, flag_0, count;
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof(a));
        cin >> n;
        if (n % 2 == 0) {
            cout << "possible\n";
            count = 0;
            for (int i = 0; i < n; ++i) {
                flag_1 = flag_0 = 0;
                if(i % 2 == 0){
                    for (int j = 0; j < n; ++j) {
                        if(j == count) {
                            a[i][j] = 1;
                            flag_1 = 1;
                        }
                        else if(j == count + 1) {
                            a[i][j] = 0;
                            flag_0 = 1;
                        }
                        else {
                            if(flag_0 && flag_1){
                                a[i][j] = 1;
                            }
                            else{
                                if(j % 2 == 1) a[i][j] = -1;
                                else a[i][j] = 1;
                            }
                        }
                    }
                }else{
                    for (int j = 0; j < n; ++j) {
                        if(j < count){
                            if(j % 2 == 1) a[i][j] = -1;
                            else a[i][j] = 1;
                        }else if(j == count) a[i][j] = 1;
                        else  a[i][j] = -1;
                    }
                    count += 2;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n - 1; ++j) {
                    cout << a[i][j] << ' ';
                }
                cout << a[i][n - 1] << endl;
            }
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}

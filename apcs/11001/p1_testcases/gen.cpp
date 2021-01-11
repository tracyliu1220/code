/*
    APCS0109 PA

    50%: n = 1, d = 0 ~ 100
    50%: 1 <= n <= 100
    
    (a0 + a1 + a2) % 3 = 0
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL) + clock());
    int n = rand() % 100 + 1;
    int d = rand() % 100 + 1;
    cout << n << ' ' << d << '\n';
    int a0, a1, a2;

    for (int i = 0; i < n; i++) {
        do {
            a0 = rand() % 100 + 1;
            a1 = rand() % 100 + 1;
            a2 = rand() % 100 + 1;
        } while ((a0 + a1 + a2) % 3 != 0);
        cout << a0 << ' ' << a1 << ' ' << a2 << '\n';
    }
}

/*
    APCS0109 PA
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    int cnt = 0;
    int sum = 0;
    int a0, a1, a2;

    for (int i = 0; i < n; i++) {
        cin >> a0 >> a1 >> a2;
        if (max({a0, a1, a2}) - min({a0, a1, a2}) >= d) {
            cnt++;
            sum += (a0 + a1 + a2) / 3;
        }
    }

    cout << cnt << ' ';
    cout << sum << '\n';
}

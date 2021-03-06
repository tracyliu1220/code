#include <bits/stdc++.h>
using namespace std;

long long pow(long long a, long long n, long long M) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1) ans = ans * a % M;
        a = a * a % M;
        n >>= 1;
    }
    return ans % M;
}

long long inv(long long a, long long p) {
    return pow(a, p - 2, p);
}

void solve() {
    long long M, a, b, x[4], y[4];
    cin >> M >> a >> b;
    cin >> x[1] >> y[1];
    cin >> x[2] >> y[2];

    // y = mx + k
    long long m = (y[2] - y[1]) * inv(x[2] - x[1], M) % M;
    long long k = (y[1] - m * x[1] % M) % M;

    long long m2 = m * m % M;
    x[3] = m2 - x[1] - x[2];
    y[3] = m * x[3] + k;

    x[3] = (x[3] % M + M) % M;
    y[3] = (y[3] % M + M) % M;
    cout << x[3] << ' ' << y[3] << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

// Copyright (C) Algo Seacow. 2020. All Rights Reserved.
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long sum = 0;
vector<long long> a, S;

void init() {
    cin >> n >> m;
    assert(1 <= n && n <= 200000);
    assert(1 <= m && m <= 20000);
    a.resize(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        assert(1 <= a[i]);
        sum += a[i];
        a[i + n] = a[i];
    }
    assert(sum <= 1000000000ll);
    S.resize(2 * n);
    long long psum = 0;
    for (int i = 0; i < 2 * n; i++) {
        psum += a[i];
        S[i] = psum;
    }
}

int next_pos(int pos, long long target) {
    target += S[pos] - a[pos];
    int L = pos;
    int R = pos + n;
    pos = lower_bound(S.begin() + L, S.begin() + R, target) - S.begin();
    return (pos + 1) % n;
}

int main() {
    init();
    int pos = 0;
    for (int cs = 1; cs <= m; cs++) {
        int target;
        cin >> target;
        assert(1 <= target && target <= sum);
        pos = next_pos(pos, target);
    }
    cout << pos << endl;
}

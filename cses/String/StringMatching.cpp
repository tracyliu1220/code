// Copyright 2021, Tsung-Ta Wu, All rights reserved.
#include <bits/stdc++.h>
using namespace std;

void KMP(int n, char s[], int f[]) {  // 1 base
    f[0] = -1, f[1] = 0;
    for (int i = 2; i <= n; i++) {
        int w = f[i - 1];
        while (w >= 0 && s[w + 1] != s[i]) w = f[w];
        f[i] = w + 1;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s, p;
    cin >> s >> p;

    string tmp = "$" + p + "@" + s;
    vector<int> f(tmp.size() + 1);
    KMP(tmp.size() - 1, tmp.data(), f.data());

    int ans = 0;
    for (int x : f) {
        if (x == (int)p.size()) ans++;
    }
    cout << ans << '\n';

    return 0;
}

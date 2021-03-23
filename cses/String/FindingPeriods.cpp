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

    string s;
    cin >> s;
    int n = s.size();
    s.insert(s.begin(), '$');
    vector<int> f(s.size());
    KMP(n, s.data(), f.data());

    vector<int> ans;
    int w = f[n];
    while (w >= 0) {
        ans.push_back(n - w);
        w = f[w];
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}

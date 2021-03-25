// Copyright 2021, Tsung-Ta Wu, All rights reserved.
#include <bits/stdc++.h>
using namespace std;

using pll = pair<long long, long long>;

const long long MOD = 1e9 + 7;
const long long x = 314159, p = 0xdefaced;

struct Node {
    long long h, pw;
    int l, r;
    Node *lc, *rc;
    Node(int _l, int _r) {
        l = _l, r = _r;
        lc = rc = nullptr;
        if (l == r) {
            h = 0, pw = x;
        } else {
            int mid = (l + r) / 2;
            lc = new Node(l, mid);
            rc = new Node(mid + 1, r);
            pw = lc->pw * rc->pw % MOD;
        }
    }
    void pull() {
        h = (lc->h + rc->h * lc->pw) % MOD;
    }
    void update(int pos, int val) {
        if (pos < l || r < pos) return;
        if (l == r) {
            h = val;
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) {
                lc->update(pos, val);
            } else {
                rc->update(pos, val);
            }
            pull();
        }
    }
    pll query(int ql, int qr) {
        if (r < ql || qr < l) return {0, 1};
        if (ql <= l && r <= qr) return {h, pw};
        pll L = lc->query(ql, qr);
        pll R = rc->query(ql, qr);
        return {(L.first + R.first * L.second) % MOD,
                L.second * R.second % MOD};
    }
};

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    Node seg(1, n);
    Node rseg(1, n);
    for (int i = 1; i <= n; i++) {
        seg.update(i, s[i - 1]);
        rseg.update(n + 1 - i, s[i - 1]);
    }

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            seg.update(pos, c);
            rseg.update(n + 1 - pos, c);
        } else {  // cmd == 2
            int ql, qr;
            cin >> ql >> qr;
            int h1 = seg.query(ql, qr).first;
            int h2 = rseg.query(n + 1 - qr, n + 1 - ql).first;
            cout << (h1 == h2 ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}

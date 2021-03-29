#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    int l, r;
    Node *lc, *rc;
    Node(int _l, int _r) {
        val = 0;
        l = _l, r = _r;
        lc = rc = nullptr;
        if (l == r) return;
        int m = (l + r) / 2;
        lc = new Node(l, m);
        rc = new Node(m + 1, r);
    }
    void update(int ql, int qr, int u) {
        if (r < ql || qr < l) return;
        if (ql <= l && r <= qr) {
            val += u;
            return;
        }
        lc->update(ql, qr, u);
        rc->update(ql, qr, u);
    }
    long long query(int x) {
        if (x < l || r < x) return 0;
        if (l == r) return val;
        push();
        return lc->query(x) + rc->query(x);
    }
    void push() {
        lc->val += val;
        rc->val += val;
        val = 0;
    }
};

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    Node root(1, n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        root.update(i, i, x);
    }
    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            root.update(l, r, u);
        } else {
            int x;
            cin >> x;
            cout << root.query(x) << ' ';
        }
    }
    cout << '\n';
    return 0;
}

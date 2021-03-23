// Copyright 2021, Tsung-Ta Wu, All rights reserved.
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Node {
    int idx;
    Node* ch[26];
    Node() {
        idx = -1;
        fill(ch, ch + 26, nullptr);
    }
};
void insert(Node* root, string s, int i) {
    for (char c : s) {
        int ci = c - 'a';
        if (root->ch[ci] == nullptr) {
            root->ch[ci] = new Node();
        }
        root = root->ch[ci];
    }
    root->idx = i;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    string s;
    Node* root = new Node();

    cin >> s;
    n = s.size();
    cin >> m;
    for (int i = 0; i < m; i++) {
        string w;
        cin >> w;
        reverse(w.begin(), w.end());
        insert(root, w, i);
    }
    s.insert(s.begin(), '$');
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        Node* ptr = root;
        for (int j = i; j >= 1; j--) {
            if (ptr->ch[s[j] - 'a'] == nullptr) break;
            ptr = ptr->ch[s[j] - 'a'];
            if (ptr->idx != -1) {
                dp[i] = (dp[i] + dp[j - 1]) % MOD;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}

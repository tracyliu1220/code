#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
//    assert(1 <= n && n <= 200000);
    vector<pair<int, int>> ps(n);
    set<pair<int, int>> ps_set;
    for (auto &v : ps) {
        cin >> v.first >> v.second;
        ps_set.insert(v);
    }
    assert(ps_set.size() == n);
    sort(ps.begin(), ps.end());
    vector<int> LIS;
    for (int i = 0 ; i < n ; i++) {
        int x = upper_bound(LIS.begin(), LIS.end(), ps[i].second) - LIS.begin();
        if (x == LIS.size())
            LIS.push_back(ps[i].second);
        else
            LIS[x] = ps[i].second;
    }
    cout << LIS.size() << '\n';
}

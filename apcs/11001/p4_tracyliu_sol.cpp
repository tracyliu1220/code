/*
    APCS0109 PD
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    
    vector<pair<int, int> > v;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    vector<int> v2;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cur = upper_bound(v2.begin(), v2.end(), v[i].second) - v2.begin();
        ans = max(cur + 1, ans);
        if (cur == v2.size())
            v2.push_back(v[i].second);
        else
            v2[cur] = v[i].second;
    }

    cout << ans << '\n';
}

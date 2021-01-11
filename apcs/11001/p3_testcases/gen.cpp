/*
    APCS0109 PC
    
    20%: n = 1000
    30%: n = 50000
    50%: n = 200000

    1 <= l <= 10^7

    n l
    p0 o0
    p1 o1
    ...
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL) + clock());
    int l = (rand() % 100000) + 10000000 - 100000;
    int n = 200000;
    cout << n << ' ' << l << '\n';

    vector<pair<int, int> > v;
    set<int> s;
    int cur;

    for (int i = 0; i < n; i++) {
        do {
            cur = rand() % (l - 1) + 1;
        } while (s.count(cur));
        s.insert(cur);
        v.push_back({cur, i + 1});
    }

    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
}

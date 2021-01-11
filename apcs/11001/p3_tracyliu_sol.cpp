/*
    APCS0109 PC
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> pos(n);

    int _pos, ord;
    for (int i = 0; i < n; i++) {
        cin >> _pos >> ord;
        pos[ord - 1] = _pos;
    }

    LL ans = 0;
    set<int> st;
    st.insert(0);
    st.insert(l);
    for (int i = 0; i < n; i++) {
        ans += (*(st.upper_bound(pos[i])) - *(prev(st.lower_bound(pos[i]))));
        st.insert(pos[i]);
    }

    cout << ans << '\n';
}

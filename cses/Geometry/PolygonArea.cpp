#include <bits/stdc++.h>
using namespace std;

using Point = pair<long long, long long>;
#define x first
#define y second

long long cross(Point u, Point v) {
    return u.x * v.y - u.y * v.x;
}

long long area(const vector<Point> &poly) {
    long long ans = 0;
    for (int i = 0, n = poly.size(); i < n; i++) {
        ans += cross(poly[i], poly[(i + 1) % n]);
    }
    return abs(ans);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<Point> poly(n);
    for (int i = 0; i < n; i++) {
        cin >> poly[i].x >> poly[i].y;
    }
    cout << area(poly) << '\n';
}

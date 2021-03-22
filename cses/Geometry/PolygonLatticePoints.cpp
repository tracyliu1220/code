#include <bits/stdc++.h>
using namespace std;

using Point = pair<long long, long long>;
#define x first
#define y second

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}
long long cross(Point u, Point v) {
    return u.x * v.y - u.y * v.x;
}

long long Area(const vector<Point> &poly) {
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
    long long twoA = Area(poly);
    long long B = 0;
    for (int i = 0; i < n; i++) {
        Point v = poly[(i + 1) % n] - poly[i];
        B += gcd(abs(v.x), abs(v.y));
    }
    // Pick's theorem : A = I + B/2 -1
    long long I = (twoA - B) / 2 + 1;
    cout << I << ' ' << B << '\n';
    return 0;
}

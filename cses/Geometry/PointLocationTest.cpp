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

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        Point a, b, c, d;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;
        long long t = cross(b - a, c - a);
        if (t > 0) {
            cout << "LEFT" << '\n';
        } else if (t == 0) {
            cout << "TOUCH" << '\n';
        } else {
            cout << "RIGHT" << '\n';
        }
    }
}

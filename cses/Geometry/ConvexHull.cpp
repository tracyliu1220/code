#include <bits/stdc++.h>
using namespace std;

using T = long long;

struct Point {
    T x, y;
    bool operator<(const Point &b) const {
        return tie(x, y) < tie(b.x, b.y);
        // return atan2(y,x) < atan2(b.y,b.x);
        assert(0 && "choose compare");
    }
    bool operator==(const Point &b) const {
        return tie(x, y) == tie(b.x, b.y);
    }
    Point operator+(const Point &b) const {
        return {x + b.x, y + b.y};
    }
    Point operator-(const Point &b) const {
        return {x - b.x, y - b.y};
    }
    Point operator*(const T &d) const {
        return {d * x, d * y};
    }
    Point operator/(const T &d) const {
        return {x / d, y / d};
    }
    T operator*(const Point &b) const {
        return x * b.x + y * b.y;
    }
    T operator%(const Point &b) const {
        return x * b.y - y * b.x;
    }
    friend T abs2(const Point &p) {
        return p.x * p.x + p.y * p.y;
    }
    friend T abs(const Point &p) {
        return sqrt(abs2(p));
    }
};

// retunr H, 第一個點會在 H 出現兩次

vector<Point> LowerHull(const vector<Point> &P) {
    vector<Point> H;
    int m = 0;
    for (int i = 0; i < (int)P.size(); i++) {
        while (m >= 2 && (H[m - 1] - H[m - 2]) % (P[i] - H[m - 2]) < 0)
            H.pop_back(), m--;
        H.push_back(P[i]), m++;
    }
    H.pop_back();
    return H;
}
vector<Point> ConvexHull(vector<Point> P) {
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    if (P.size() == 1) return P;
    vector<Point> lower = LowerHull(P);
    reverse(P.begin(), P.end());
    vector<Point> upper = LowerHull(P);
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    vector<Point> H = ConvexHull(points);
    cout << H.size() << '\n';
    for (int i = 0; i < (int)H.size(); i++) {
        cout << H[i].x << ' ' << H[i].y << '\n';
    }
}

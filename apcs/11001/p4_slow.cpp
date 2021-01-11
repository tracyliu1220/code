#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> ps(n);
	for (auto &v : ps)
		cin >> v.first >> v.second;
	sort(ps.begin(), ps.end());
	vector<int> lis(n, 0);
	int ans = 0;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < i ; j++) {
			if (ps[j].second <= ps[i].second)
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}
	cout << *max_element(lis.begin(), lis.end()) + 1<< '\n';
}

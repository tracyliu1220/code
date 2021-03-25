// Copyright 2021, Tsung-Ta Wu, All rights reserved.
#include <bits/stdc++.h>
using namespace std;

void Manacher(int n, char s[], int r[]) {
    fill(r, r + n, 0);
    for (int i = 0; i < n; i++) {
        while (0<= i-r[i] && i+r[i]<n && s[i-r[i]] == s[i+r[i]]){
            r[i]++;
            r[i+r[i]] = max(r[i+r[i]], min(r[i-r[i]], );
        }

    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    return 0;
}

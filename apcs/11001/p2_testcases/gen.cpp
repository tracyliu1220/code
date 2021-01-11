#include <bits/stdc++.h>
using namespace std;

template <typename T>
void write(vector<T> &vec, ofstream &out) {
    int n = vec.size();
    for (int i = 0; i < n; i++)
        out << vec[i] << " \n"[i + 1 == n];
}
template <typename T>
void write(vector<vector<T>> &vec, ofstream &out) {
    for (auto &v : vec)
        write(v, out);
}

void gen(int n, int m, int k, string basename) {
    ofstream in(basename + ".in");
    in << n << ' ' << m << ' ' << k << '\n';
    vector<vector<int>> flow(n, vector<int>(m));
    for (auto &vv : flow)
        for (auto &v : vv)
            v = rand() % 1500 + 1;
    vector<vector<int>> kase(k, vector<int>(n));
    for (auto &vv : kase)
        for (auto &v : vv)
            v = rand() % m;
    
    write(flow, in);
    write(kase, in);
}

void testcase1(const char* filename) {
    int n = 1;
    int m = rand() % 50 + 1;
    int k = 1;
    gen(n, m, k, filename);
}
void testcase2(const char* filename) {
    int n = 1;
    int m = rand() % 50 + 1;
    int k = rand() % 50 + 1;
    gen(n, m, k, filename);
}
void testcase3(const char* filename) {
    int n = rand() % 50 + 1;
    int m = rand() % 50 + 1;
    int k = rand() % 50 + 1;
    gen(n, m, k, filename);
}

int main(int argc, char **argv) {
    srand(time(NULL));
    if (argc - 1 != 2) {
        cout << "Usage: " << argv[0] << " #testcase filename\n";
        exit(1);
    }
    switch (atoi(argv[1])) {
        case 1:
            testcase1(argv[2]);
            break;
        case 2:
            testcase2(argv[2]);
            break;
        case 3:
            testcase3(argv[2]);
            break;
    }
}

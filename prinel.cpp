#include <bits/stdc++.h>
using namespace std;
#define INF 2000000

int main() {
    int n, k, i, nr, point, j;
    ifstream fin("prinel.in");
    ofstream fout("prinel.out");
    vector<int> target;
    vector<int> points;
    int max_target = 0;
    fin >> n >> k;
    for (i = 0; i < n; i++) {
        fin >> nr;
        target.push_back(nr);
        if (nr > max_target) {
            max_target = nr;
        }
    }
    for (i = 0; i < n; i++) {
        fin >> point;
        points.push_back(point);
    }
    vector<int> v(max_target + 1, INF);
    v[1] = 0;
    for (i = 1; i <= max_target; i++) {
        for (j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                if (i + j <= max_target) {
                    int minim = std::min(v[i + j], 1 + v[i]);
                    v[i + j] = minim;
                }
                if (i + (i / j) <= max_target) {
                    int minim2 = std::min(v[i + (i / j)], 1 + v[i]);
                    v[i + (i / j)] = minim2;
                }
            }
        }
    }
    int s = 0, p = 0;
    for (i = 0; i < n; i++) {
        s += v[target[i]];
        p += points[i];
    }
    if (s >= k) {
        vector<int> dp(k + 1, 0);
        for (i = 1; i < n + 1; i++) {
            for (j = k; j >= 0; j--) {
                if (v[target[i - 1]] <= j) {
                    dp[j] = std::max(dp[j],
                    dp[j - v[target[i - 1]]] + points[i - 1]);
                }
            }
        }
        fout << dp[k] << endl;
    } else {
        fout << p << endl;
    }
    fin.close();
    fout.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long recursive_call(long inverted, long i, long j, long n) {
    if (n == 1) {
        return inverted;
    }
    if (i > n / 2 && j > n / 2) {
        return recursive_call(inverted + 1, i - n / 2, j - n / 2, n / 2);
    }
    if (i > n / 2 && j <= n / 2) {
        return recursive_call(inverted, i - n / 2, j, n / 2);
    }
    if (i <= n / 2 && j > n / 2) {
        return recursive_call(inverted, i, j - n / 2, n / 2);
    }
    return recursive_call(inverted, i, j, n / 2);
}

int main() {
    long n, k, i, x, y;
    ifstream fin("walsh.in");
    ofstream fout("walsh.out");
    fin >> n >> k;
    for (i = 0; i < k; i++) {
        fin >> x >> y;
        long result = recursive_call(0, x, y, n);
        if (result % 2 == 0) {
            fout << 0 << endl;
        } else {
            fout << 1 << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}

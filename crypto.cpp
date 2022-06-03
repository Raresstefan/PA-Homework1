#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int nr_distinct_chars(string s) {
    int i;
    unordered_set<char> set;
    for (i = 0; i < s.size(); i++) {
        set.insert(s[i]);
    }
    return set.size();
}

int main() {
    int n, l, i, j;
    string k, s;
    ifstream fin("crypto.in");
    ofstream fout("crypto.out");
    fin >> n >> l;
    fin >> k;
    fin >> s;
    vector<long> v(n + 1, 0);
    v[0] = 1;
    long modulo = 1000000007;
    long distinct_chars = nr_distinct_chars(s);
    for (i = 1; i <= n; i++) {
        if (k[i - 1] != '?') {
            v[i] = v[i - 1] % modulo;
        } else {
            v[i] = ((v[i - 1] % modulo) * (distinct_chars % modulo)) % modulo;
        }
    }
    vector<vector<long>> matrix(n + 1, vector<long>(l + 1));
    for (i = 0; i <= l; i++) {
        matrix[0][i] = 0;
    }
    for (i = 0; i <= n; i++) {
        matrix[i][0] = v[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j<= l; j++) {
            if (k[i - 1] == '?') {
                matrix[i][j] = (((matrix[i - 1][j] % modulo)
                * (distinct_chars) % modulo)
                % modulo +
                matrix[i - 1][j - 1] % modulo) % modulo;
            } else {
                if (k[i - 1] == s[j - 1]) {
                    matrix[i][j] = (matrix[i - 1][j - 1] % modulo +
                    matrix[i - 1][j] % modulo) % modulo;
                } else {
                    matrix[i][j] = matrix[i - 1][j] % modulo;
                }
            }
        }
    }
    fout << matrix[n][l] % modulo << endl;
    fin.close();
    fout.close();
    return 0;
}

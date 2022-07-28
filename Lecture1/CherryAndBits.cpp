// https://www.codechef.com/submit/CENS20A
#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    vector<vector<int>> delta(n + 1, vector<int>(m + 1));
    int q;
    cin >> q;
    
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2, --x1, --y1, --x2, --y2;
        delta[x1][y1] += 1;
        delta[x2 + 1][y1] -= 1;
        delta[x1][y2 + 1] -= 1;
        delta[x2 + 1][y2 + 1] += 1;
    }
    
    for (int c = 0; c < m; c++) {
        for (int r = 1; r < n; r++) {
            delta[r][c] += delta[r - 1][c];
        }
    }
    
    for (int r = 0; r < n; r++) {
        for (int c = 1; c < m; c++) {
            delta[r][c] += delta[r][c - 1];
        }
    }
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (delta[r][c] % 2 == 1) {
                s[r][c] ^= '0' ^ '1';
            }
        }
        cout << s[r] << endl;
    }
    return 0;
}
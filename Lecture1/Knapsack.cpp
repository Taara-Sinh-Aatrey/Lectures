// https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const long long INF = 1e18L + 5;

#define weight first
#define value second

int main() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    const int MAX_VAL = 1e5;
    vector<long long> dp(MAX_VAL + 1, INF);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        for(int val = MAX_VAL; val >= a[i].value; val--) {
            dp[val] = min(dp[val], dp[val - a[i].value] + a[i].weight);
        }
    }
    
    for (int i = MAX_VAL; i >= 0; i--) {
        if (dp[i] <= w) {
            cout << i;
            return 0;
        }
    }
    assert(false);
}
// https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;

int max_cows(vector<int> &pos, int dist) {
    int cows = 1, prev_i = 0;
    for (int i = 1; i < (int) pos.size(); i++) {
        if (pos[i] - pos[prev_i] >= dist) {
            cows++;
            prev_i = i;
        }
    }
    return cows;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            cin >> pos[i];
        }
        sort(pos.begin(), pos.end());
        
        int low = 1, high = pos.back() - pos.front();
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int cows = max_cows(pos, mid);
        
            if (cows >= c) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        cout << high << endl;
    }
    return 0;
}
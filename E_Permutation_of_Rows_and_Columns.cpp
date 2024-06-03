#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        
        // Read matrix a
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        // Read matrix b
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }

        // Create sets of rows and columns for a and b
        vector<unordered_multiset<int>> rows_a(n), rows_b(n), cols_a(m), cols_b(m);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rows_a[i].insert(a[i][j]);
                cols_a[j].insert(a[i][j]);
                rows_b[i].insert(b[i][j]);
                cols_b[j].insert(b[i][j]);
            }
        }

        // Check if sets match
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            if (rows_a[i] != rows_b[i]) {
                possible = false;
                break;
            }
        }

        for (int j = 0; j < m; ++j) {
            if (cols_a[j] != cols_b[j]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for gcd

using namespace std;

bool is_non_decreasing(const vector<int>& b) {
    for (size_t i = 1; i < b.size(); ++i) {
        if (b[i-1] > b[i]) {
            return false;
        }
    }
    return true;
}

vector<int> compute_gcd_sequence(const vector<int>& a) {
    vector<int> b;
    for (size_t i = 0; i < a.size() - 1; ++i) {
        b.push_back(gcd(a[i], a[i+1]));
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Check if initial GCD-sequence is non-decreasing
        vector<int> b = compute_gcd_sequence(a);
        if (is_non_decreasing(b)) {
            cout << "YES" << endl;
            continue;
        }

        bool possible = false;
        
        // Try removing each element and check the GCD-sequence
        for (int i = 0; i < n; ++i) {
            vector<int> new_a;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    new_a.push_back(a[j]);
                }
            }
            vector<int> new_b = compute_gcd_sequence(new_a);
            if (is_non_decreasing(new_b)) {
                possible = true;
                break;
            }
        }
        
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

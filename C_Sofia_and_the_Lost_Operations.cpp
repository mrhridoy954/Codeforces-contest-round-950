#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int m;
        cin >> m;
        vector<int> d(m);
        for (int i = 0; i < m; ++i) {
            cin >> d[i];
        }

        unordered_map<int, int> requiredChanges;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                requiredChanges[b[i]]++;
            }
        }

        unordered_map<int, int> availableChanges;
        for (int i = 0; i < m; ++i) {
            availableChanges[d[i]]++;
        }

        bool possible = true;
        for (const auto &pair : requiredChanges) {
            if (availableChanges[pair.first] < pair.second) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}

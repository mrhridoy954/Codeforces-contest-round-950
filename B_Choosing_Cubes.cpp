#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int favoriteValue = a[f - 1]; 
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end(), greater<int>());

        int favoriteCount = count(a.begin(), a.end(), favoriteValue);
           int removedFavoriteCount = count(sortedA.begin(), sortedA.begin() + k, favoriteValue);

        if (favoriteCount == 1) {
            if (find(sortedA.begin(), sortedA.begin() + k, favoriteValue) != sortedA.begin() + k) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (removedFavoriteCount == favoriteCount) {
                cout << "YES" << endl;
            } else if (removedFavoriteCount == 0) {
                cout << "NO" << endl;
            } else {
                cout << "MAYBE" << endl;
               }
        }
    }

    return 0;
}

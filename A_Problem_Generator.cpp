#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    
    while (t--) {
        int n, m; 
        cin >> n >> m;
        
        string problems;
        cin >> problems;
        
        unordered_map<char, int> problemCount;
        
        for (char problem : problems) {
            problemCount[problem]++;
        }
        
        int minNewProblems = 0;
        
        for (char level = 'A'; level <= 'G'; level++) {
            if (problemCount[level] < m) {
                minNewProblems += (m - problemCount[level]);
            }
        }
        
        cout << minNewProblems << endl;
    }
    
    return 0;
}

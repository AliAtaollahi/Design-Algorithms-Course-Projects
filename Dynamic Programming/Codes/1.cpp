#include <bits/stdc++.h>
using namespace std;

#define MAX 2200


int main() {
    int n, m;
    int in[MAX][MAX], dp[MAX][MAX];
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> in[i][j];
        }
    }
    
    dp[0][0] = in[0][0];
    
    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i - 1] + in[0][i];
    }
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + in[i][0];
        
        for (int j = 1; j <= m - 1; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + in[i][j];
        }
        
        for (int j = m - 2; j >= 1; j--) {
            dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i][j + 1])) + in[i][j];
        }
        
        dp[i][0] = min(dp[i - 1][0], dp[i][1]) + in[i][0];
    }
    
    cout << dp[n - 1][m - 1];
    
    return 0;
}

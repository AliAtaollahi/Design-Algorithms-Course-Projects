#include <bits/stdc++.h>
using namespace std;

const long long MAX = 320;
const long long MOD = 1e9 + 7;

long int n, min_k;
long int input[MAX], sorted_input[MAX], sorted_orders[MAX];
long int dp[MAX][MAX][MAX], dp_sum[MAX][MAX][MAX];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    copy(begin(input), end(input), begin(sorted_input));
    sort(sorted_input, sorted_input + n);
    map<long int, long int> map_;
    for (long int i = 0; i < n; i++)
        map_[sorted_input[i]] = i + 1;
    for (long int i = 0; i < n; i++)
        sorted_orders[i] = map_[input[i]];
    int start;
    for (int length = 0; length < n; length++) {
        for (int end = length + 1; end <= n; end++) {
            start = end - length - 1;
            for (int order = n + 1; order >= 0; order--) {
                dp[start][end][order] = (length == 0) ? order == sorted_orders[start] :
                    (sorted_orders[end - 1] == order && sorted_orders[start] == order) ?
                    ((dp[start + 1][end][order] + dp[start][end - 1][order] - dp[start + 1][end - 1][order] + 1 + dp_sum[start + 1][end - 1][order]) % MOD + MOD) % MOD :
                    ((dp[start + 1][end][order] - dp[start + 1][end - 1][order] + dp[start][end - 1][order]) % MOD + MOD) % MOD;
                dp_sum[start][end][order] = (dp_sum[start][end][order + 1] + dp[start][end][order]) % MOD;
            }
        }
    }
    cout << dp_sum[0][n][0];
}

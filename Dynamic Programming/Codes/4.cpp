#include <bits/stdc++.h>
using namespace std;

const int MAX = 5100;

long long dp[MAX][MAX];
long long in[MAX];
long long n, ans;

long long find_min_move(long long left, long long right, long long height) {
    long long min_col = dp[left][right];
    if (left == right)
        return (height == in[min_col]) ? 0 : 1;

    if (left > right)
        return 0;

    long long sum_left = 0, sum_right = 0;
    if (min_col > 0)
        sum_left = find_min_move(left, min_col - 1, in[min_col]);
    if (min_col < n - 1)
        sum_right = find_min_move(min_col + 1, right, in[min_col]);
    return min(right - left + 1, in[min_col] - height + sum_left + sum_right);
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> in[i];
    memset(dp, -1, sizeof(dp));
    for (long long i = 0; i < n; i++) {
        for (long long j = i; j < n; j++) {
            long long l = j - i;
            dp[l][l + i] = (i == 0) ? j :
                           (in[dp[l][l + i - 1]] > in[dp[l + 1][l + i]]) ? dp[l + 1][l + i] :
                           dp[l][l + i - 1];
        }
    }

    cout << find_min_move(0, n - 1, 0);
}

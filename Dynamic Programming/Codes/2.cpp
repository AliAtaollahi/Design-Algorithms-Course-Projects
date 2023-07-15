#include <bits/stdc++.h>
using namespace std;

const int MAX = 1050;
vector<int> adj[MAX], scc[MAX];
int n, m, t, src, dst, sum_e, sum_d, scc_num, seen[MAX], e[MAX], d[MAX], dp[MAX][MAX];

void dfs(int v) {
    vector<int> nodes = {v};
    seen[v] = ++scc_num;
    while (!nodes.empty()) {
        v = nodes.back();
        seen[v] = scc_num;
        while (!adj[v].empty()) {
            int u = adj[v].back();
            if (!seen[u]) {
 				nodes.push_back(u);
                v = u;
 				seen[v] = scc_num;
            } else
                adj[v].pop_back();
        }
        nodes.pop_back();
    }
}

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        cin >> e[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < m; i++) {
        cin >> src >> dst;
        src--;
        dst--;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }

    for (int i = 0; i < n; i++)
        if (!seen[i])
            dfs(i);
    for (int i = 0; i < n; i++)
        scc[seen[i]].push_back(i);
    for (int i = 1; i <= scc_num; i++) {
        for (int j = 0; j <= t; j++) {
            sum_e = 0, sum_d = 0;
            dp[i][j] = dp[i - 1][j];
            for (auto x : scc[i]) {
 				int scc_it = x;
                sum_e += e[scc_it];
                sum_d += d[scc_it];
                if (e[scc_it] > j)
                    continue;
                else
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - e[scc_it]] + d[scc_it]);
            }
            if (sum_e <= j)
 				dp[i][j] = max(dp[i][j], dp[i - 1][j - sum_e] + sum_d);
        }
    }
    cout << dp[scc_num][t] << endl;
}

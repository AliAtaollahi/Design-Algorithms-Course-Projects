#include <bits/stdc++.h>
#define MAX_VERTEX 1005 + 5

using namespace std;

int main() {
    int n, m, f, r, u;
    int dst[MAX_VERTEX][MAX_VERTEX];
    cin >> n;
    string output = "";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dst[i][j];
        }
    }

    for (int l = 0; l < n; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp = dst[l][j] + dst[i][l];
                if (dst[i][l] + dst[l][j] < dst[i][j]) {
                    dst[i][j] = temp;
                }
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> f >> r >> u;
        output += to_string(dst[f][r] + dst[r][u]) + ' ' + to_string(dst[f][r] + dst[r][u] - dst[f][u]) + '\n';
    }

    cout << output;
    return 0;
}

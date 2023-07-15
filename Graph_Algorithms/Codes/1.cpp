#include <bits/stdc++.h>
#define INF 1e9 + 7
#define INIT 0
#define MAX_EDGE 1005 + 5
#define MAX_VERTEX 1005 + 5

using namespace std;

int main() {
    long int vertic_num, edges_num, inp, src[MAX_EDGE], dest[MAX_EDGE];
    long double weights[MAX_EDGE];
    vector<long double> dst(MAX_VERTEX, INF);
    cin >> vertic_num >> edges_num;
    for (int i = 0; i < edges_num; i++)
        cin >> src[i] >> dest[i] >> weights[i];

    dst[INIT] = 0;
    for (int i = 0; i < edges_num; i++)
        weights[i] = -log(weights[i]);

    for (int i = 0; i < vertic_num; i++) {
        for (int j = 0; j < edges_num; j++) {
            if (dst[dest[j]] > dst[src[j]] + weights[j])
                dst[dest[j]] = dst[src[j]] + weights[j];
        }
    }

    bool res = false;
    for (int i = 0; i < edges_num; i++) {
        if (dst[dest[i]] > dst[src[i]] + weights[i])
            res = true;
    }

    cout << (res ? "YES" : "NO");
    return 0;
}

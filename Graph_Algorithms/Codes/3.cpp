#include <bits/stdc++.h>

using namespace std;

#define MAXN 100015 + 5
#define INF 1e16 + 5

struct Edge {
    long long neighbour, w;
};

struct EdgeWithWeight {
    long long w, u, v;
};

vector<vector<Edge>> first_edges(MAXN);
vector<EdgeWithWeight> all_edges;
vector<vector<int>> cut_vertices_edge(MAXN);
set<pair<int, int>> set_queue;
int heights[MAXN], max_heights[MAXN], n, m, x, s, t;
vector<int> cut_vertices;
bool is_mark[MAXN];
long long answer = INF, first_try_dst[MAXN], second_try_dst[MAXN], third_try_dst[MAXN];

void update_max_heights(int v, int first, int second) {
    max_heights[v] = min(max_heights[first], max_heights[second]);
}

void dijkstra(long long dst[], int v) {
    dst[v] = 0;
    set_queue.insert({0, v});
    while (!set_queue.empty()) {
        int u = set_queue.begin()->second;
        set_queue.erase(set_queue.begin());
        for (auto edge : first_edges[u]) {
            int vertex_index = edge.neighbour, w = edge.w;
            if (dst[u] + w < dst[vertex_index]) {
                dst[vertex_index] = dst[u] + w;
                set_queue.erase({dst[vertex_index], vertex_index});
                set_queue.insert({dst[vertex_index], vertex_index});
            }
        }
    }
}

void dfs(int v) {  
    is_mark[v] = true;
    max_heights[v] = heights[v];
    bool check = false;
    for (int u : cut_vertices_edge[v]) {
        if (!is_mark[u]) {
            heights[u] = heights[v] + 1;
            dfs(u);
            update_max_heights(v, u, v);
            check = (max_heights[u] >= heights[v] ? true : check);
        }
        else if (heights[v] - heights[u] != 1) 
            update_max_heights(v, v, u);  
    }
    if (s == v || t == v || check)
        cut_vertices.push_back(v);
}

int main() {
    cin >> n >> m >> x >> s >> t;
    x--, s--, t--;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        first_edges[--u].push_back({--v, w});
        first_edges[v].push_back({u, w});
        all_edges.push_back({w, u, v});
    }    
    for (int i = 0; i < n; i++)
        first_try_dst[i] = second_try_dst[i] = third_try_dst[i] = INF; 
    dijkstra(first_try_dst, s);
    dijkstra(second_try_dst, t);
    for (auto edge : all_edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        if (min(first_try_dst[u] + second_try_dst[v], 
            first_try_dst[v] + second_try_dst[u]) + w == first_try_dst[t]) {
            cut_vertices_edge[u].push_back(v);
            cut_vertices_edge[v].push_back(u);    
        }
    }
    dfs(s);
    dijkstra(third_try_dst, x);    
    for (auto x : cut_vertices) 
        answer = min(answer, third_try_dst[x]);
    cout << (answer != INF ? answer : -1);
    return 0;
}

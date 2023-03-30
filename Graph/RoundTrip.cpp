// Find a cycle >= 3 in length
// Run dfs, search for cycles >= 3, do not go through visited again
// Keep track of overall visited and current path

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

#define endl '\n'
#define ll long long
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#include </Users/akhilkammila/Competitive Programming/debug.h>
#else
#define DEBUG(...) 47;
#endif

int N, M;
vector<vector<int>> edges;
unordered_set<int> visited;
vector<int> previous;

int dfs(int u, int prev) {
    DEBUG(u, prev);
    DEBUG(visited);
    // ran into a node already on the path
    if (visited.count(u)) return u;
    visited.insert(u);

    for(int v : edges[u]) {
        if (v == prev) continue;
        previous[v] = u;
        int x = dfs(v, u);
        if (x != -1) return x;
    }
    return -1;
}

void backtrace(int u) {
    DEBUG(u, previous);
    vector<int> answ;
    answ.push_back(u);
    int curr = previous[u];

    while (curr != u) {
        answ.push_back(curr);
        curr = previous[curr];
    }
    answ.push_back(u);

    // print
    cout << answ.size() << '\n';
    for(int i : answ) {
        cout << i+1 << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read in inputs
    cin >> N >> M;
    edges.resize(N, vector<int>());
    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b, a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    previous.resize(N, -1);

    // Keep visited set and path set
    // Run dfs from each node, keeping track of depth
    for(int i = 0; i < N; i++) {
        if (visited.count(i)) continue;

        int x = dfs(i, -1);
        if (x != -1) {
            backtrace(x);
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
        // If we reach a node that was already on the same path, at a depth >= 4, print out the path backwards
        // If we reach a node on same path, at depth < 4, return
        // If we reach a node that was already visited but not on path, (this shouldnt happen)

}
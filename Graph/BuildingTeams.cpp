// Simple DFS

#include <iostream>
#include <vector>
#include <queue>
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
vector<int> teams;

// team = true means assign to team 2, otherwise assign to team 1
// if we reached a contradiction, return false
bool dfs(int u, bool team) {
    if (teams[u] == (int)!team) return false; //if opposite, return false
    if (teams[u] != -1) return true; // already processed

    teams[u] = team;

    for(int v : edges[u]) {
        if (!dfs(v, !team)) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // read in input
    cin >> N >> M;
    edges.resize(N, vector<int>());
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b, a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    teams.resize(N, -1);

    // run dfs on each node, and we color the neighboring nodes a dif color
    // aka. we assign it to a dif team
    for(int i = 0; i < N; i++) {
        DEBUG(teams);

        // if it is already assigned we skip
        if (teams[i] != -1) continue;

        // search through neighboring nodes
        if (!dfs(i, true)) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }

    for(int i = 0; i < teams.size(); i++) {
        cout << teams[i] + 1 << ' ';
    }

}
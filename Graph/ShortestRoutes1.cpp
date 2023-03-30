// Dijstras

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

#define int long long
#define pii pair<int,int>

int N, M;
vector<vector<pii>> adjList; //stores that a can reach {b, with cost c}
priority_queue<pii, vector<pii>, greater<pii>> q;
vector<int> distances;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read inputs
    cin >> N >> M;
    adjList.resize(N, vector<pii>());
    for(int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c, a--, b--;
        adjList[a].push_back(make_pair(c, b));
    }
    distances.resize(N, -1);

    // Get lowest edge weight
    q.push(make_pair(0, 0)); // with cost 0, ca get to vertex 0
    while(q.size()) {
        pii r = q.top();
        q.pop();
        int c = r.first, u = r.second;
        DEBUG(r);

        if (distances[u] != -1) continue;
        distances[u] = c;

        // add adjacent edges to queue
        for(pii neighbor : adjList[u]) {
            q.push(make_pair(neighbor.first + c, neighbor.second));
        }
        DEBUG(r, distances);
    }

    for(int i : distances) {
        cout << i << ' ';
    }
}
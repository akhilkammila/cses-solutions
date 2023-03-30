// Simple BFS

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
vector<vector<int>> adjacencyList;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read in inputs
    cin >> N >> M;
    adjacencyList.resize(N, vector<int>());
    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b, a--, b--;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }

    // BFS from node 0
    queue<int> q;
    unordered_set<int> visited;
    vector<int> from(N, -1);

    DEBUG(adjacencyList);

    q.push(0);
    visited.insert(0);

    int length = 0;
    while(q.size()) {
        DEBUG(q);
        int s = q.size();
        for(int i = 0; i < s; i++) { // pop all elements in queue
            int u = q.front();
            q.pop();

            // exit condition
            if (u + 1 == N) {
                vector<int> backtrace;
                while(u != -1) {
                    backtrace.push_back(u);
                    u = from[u];
                }

                cout << length + 1<< '\n';
                for(int i = backtrace.size() - 1; i >= 0; i--) {
                    cout << backtrace[i] + 1 << ' ';
                }
                return 0;
            }

            for(int v : adjacencyList[u]) {
                if (!visited.count(v)) {
                    visited.insert(v);
                    q.push(v);
                    from[v] = u;
                }
            }
        }
        length++;
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
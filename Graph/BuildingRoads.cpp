#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'
#define ll long long
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#include </Users/akhilkammila/Competitive Programming/debug.h>
#else
#define DEBUG(...) 47;
#endif

struct DisjointSet
{
    vector<int> parent;
    vector<int> size;
    int numComponents;
    int maxSize;

    DisjointSet(int n)
    {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        numComponents = n;
        maxSize = 1;
    }

    int find(int a)
    {
        while (a != parent[a])
        {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }

    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
        {
            return false;
        }
        if (size[a] >= size[b])
        {
            parent[b] = a;
            size[a] += size[b];
            maxSize = max(maxSize, size[a]);
        }
        else
        {
            parent[a] = b;
            size[b] += size[a];
            maxSize = max(maxSize, size[b]);
        }
        numComponents -= 1;
        return true;
    }
};

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    DisjointSet roads = DisjointSet(N);

    int roadsNeeded = N-1;

    for(int i = 0, u, v; i < M; i++) {
        cin >> u >> v, u--, v--;
        if (roads.join(u, v)) roadsNeeded -= 1;
    }
    cout << roadsNeeded << '\n';

    for(int i = 0; i < N - 1; i++) {
        if (roads.join(i, i+1))
            cout << i+1 << ' ' << i+2 << '\n';
    }
}
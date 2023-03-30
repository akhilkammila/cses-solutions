// Flood fill the rooms

#include <iostream>
#include <vector>
#include <string>
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

vector<string> building;
vector<vector<bool>> visited;
int H, W;

vector<int> rChange = {0, 0, 1, -1};
vector<int> cChange = {1, -1, 0, 0};

void floodFill(int r, int c)
{
    if (r < 0 || r >= H)
        return;
    if (c < 0 || c >= W)
        return;
    if (visited[r][c])
        return;
    if (building[r][c] != '.')
        return;

    visited[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        floodFill(r + rChange[i], c + cChange[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read in inputs
    cin >> H >> W;
    string l;
    for (int i = 0; i < H; i++)
    {
        cin >> l;
        building.push_back(l);
    }
    visited.resize(H, vector<bool>(W, false));

    int rooms = 0;
    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            if (building[r][c] == '.' && !visited[r][c])
            {
                floodFill(r, c);
                rooms += 1;
            }
        }
    }
    cout << rooms << '\n';
}
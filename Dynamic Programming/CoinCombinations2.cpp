#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define ll long long
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#include </Users/akhilkammila/Competitive Programming/debug.h>
#else
#define DEBUG(...) 47;
#endif

const int MOD = 1e9 + 7;
int N, X;
vector<vector<int>> dp;
vector<int> coins;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read in inputs
    cin >> N >> X;
    for (int i = 0, a; i < N; i++)
    {
        cin >> a;
        coins.push_back(a);
    }
    // N is # of coins, X is prices
    dp.resize(N, vector<int>(X + 1, 0));
    dp[0][0] = 1;
    // Dp this
    for (int i = 0; i < N; i++) // the current coin we are on
    {
        for (int j = 0; j <= X; j++) // the current price
        {
            // possibility 1
            int coinValue = coins[i];
            if (j - coinValue >= 0)
                dp[i][j] += dp[i][j - coinValue];
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[N - 1][X] << '\n';
}
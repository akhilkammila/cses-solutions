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
vector<int> dp;
int N, X;
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
    dp.resize(X + 1, 0);
    dp[0] = 1;

    // Dp
    for (int i = 1; i <= X; i++)
    {
        int sum = 0;
        // loop through each coin
        for (int j = 0; j < N; j++)
        {
            if (i - coins[j] >= 0)
                sum += dp[i - coins[j]];
            sum %= MOD;
        }
        dp[i] = sum;
    }
    cout << dp[X] << '\n';
}
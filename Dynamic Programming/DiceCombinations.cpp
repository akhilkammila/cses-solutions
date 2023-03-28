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
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dp.resize(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        ll ways = 0;
        for (int j = max(i - 6, 0); j < i; j++)
        {
            ways += dp[j];
            ways %= MOD;
        }
        if (i <= 6)
            ways += 1;
        dp[i] = ways % MOD;
    }
    cout << dp[N] << '\n';
}
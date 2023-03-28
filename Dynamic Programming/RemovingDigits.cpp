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

int N;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dp.resize(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        // Get the digits
        vector<int> digits;
        int i2 = i;
        while (i2)
        {
            if (i2 % 10 != 0)
                digits.push_back(i2 % 10);
            i2 /= 10;
        }
        // DEBUG(digits);

        // Transition state
        int steps = 1 << 30;
        for (int j = 0; j < digits.size(); j++)
        {
            int digit = digits[j];
            if (i - digit >= 0)
                steps = min(steps, dp[i - digit] + 1);
        }
        dp[i] = steps;
    }

    cout << dp[N] << '\n';
    // DEBUG(dp);
}
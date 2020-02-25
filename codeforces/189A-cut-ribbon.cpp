#include <climits>
#include <iostream>

using namespace std;

int n;
int v[3];

int  mem[4010];
bool vis[4010];

int dp(int remainder)
{
    if (remainder == 0)
        return 0;
    else if (remainder < 0)
        return INT_MIN;
    if (vis[remainder])
        return mem[remainder];

    int ans = INT_MIN;

    for (int i = 0; i < 3; ++i)
    {
        ans = max(ans, 1 + dp(remainder - v[i]));
    }

    vis[remainder] = true;
    mem[remainder] = ans;

    return ans;
}

int main(void)
{
    cin >> n >> v[0] >> v[1] >> v[2];

    cout << dp(n) << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b)
{
    if (a < b)
        return b - a;
    else
    {
        int ans = 0;
        while (a > b)
        {
            if (a % 2 == 0)
                a /= 2;
            else
                a++;
            ans++;
        }
        return ans + b - a;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int NMAX = 3e3 + 11;

string s, t;
int    mem[NMAX][NMAX];

string reconstruct(int i, int j)
{
    if (i == 0 or j == 0)
        return "";
    if (s[i - 1] == t[j - 1])
        return reconstruct(i - 1, j - 1) + s[i - 1];
    else
    {
        if (mem[i - 1][j] > mem[i][j - 1])
            return reconstruct(i - 1, j);
        else
            return reconstruct(i, j - 1);
    }
}

string solve(void)
{
    int n = s.size();
    int m = t.size();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i - 1] == t[j - 1])
                mem[i][j] = mem[i - 1][j - 1] + 1;
            else
                mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
        }
    }

    return reconstruct(n, m);
}

int main(void)
{
    cin >> s >> t;

    cout << solve() << endl;
    return 0;
}

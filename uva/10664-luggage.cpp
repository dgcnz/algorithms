#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int NMAX = 20 + 11;
const int SMAX = 200 + 11;

int w[NMAX], tsum, n;
int mem[NMAX][SMAX];

void read_integers(void)
{

    int    x, i = 0;
    string s;
    tsum = 0;

    getline(cin, s);
    stringstream ss(s);

    while (ss >> x)
    {
        tsum += x;
        w[i++] = x;
    }
    n = i;
}

int dp(int pos, int capacity)
{
    int &ans = mem[pos][capacity];
    if (pos == n)
        return 0;
    if (ans != -1)
        return ans;
    if (capacity - w[pos] >= 0)
        ans = dp(pos + 1, capacity - w[pos]) + w[pos];
    return max(ans, dp(pos + 1, capacity));
}

bool solve(void)
{
    int ans;
    if (tsum % 2 == 1)
        return false;

    memset(mem, -1, sizeof(mem));
    ans = dp(0, tsum / 2);
    return ans == tsum / 2;
}

int main(void)
{
    int m;
    cin >> m;

    cin.ignore();

    while (m--)
    {
        read_integers();
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 21;

int  n;
char table[NMAX][NMAX];
bool vis[NMAX][NMAX];

// N NE E SE S SW W NW
vector<ii> directions = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

bool cmp(string const &a, string const &b)
{
    if (isz(a) == isz(b))
        return a < b;
    else
        return isz(a) < isz(b);
};

set<string, decltype(cmp) *> unique_words(cmp);

inline bool in_bounds(int r, int c)
{
    return 0 <= r and r < n and 0 <= c and c < n;
}

vector<ii> neighbors(int r, int c)
{
    vector<ii> ans;
    for (auto [dr, dc] : directions)
        if (in_bounds(r + dr, c + dc) and table[r + dr][c + dc] > table[r][c])
            ans.emplace_back(r + dr, c + dc);
    return ans;
}

void backtrack(int r, int c, string s = "")
{
    vis[r][c] = true;
    s += table[r][c];
    if (isz(s) >= 3)
        unique_words.emplace(s);
    for (auto [rr, cc] : neighbors(r, c))
    {
        if (vis[rr][cc])
            continue;
        backtrack(rr, cc, s);
    }
    vis[r][c] = false;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        unique_words.clear();
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                cin >> table[r][c];

        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                backtrack(r, c);

        for (auto s : unique_words)
            cout << s << endl;
        if (t > 0)
            cout << endl;
    }

    return 0;
}

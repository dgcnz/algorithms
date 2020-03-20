#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using vi = vector<int>;

const int NMAX = 10e4;

struct state
{
    int a[4];
    int depth;

    state(vi v) { copy(v.begin(), v.end(), a); }
    state(void) {}

    int index(void) const
    {
        int ans = 0, pten = 1;
        for (int i = 0; i < 4; ++i)
        {
            ans += a[i] * pten;
            pten *= 10;
        }
        return ans;
    }
    void cin_init(void)
    {
        for (int i = 0; i < 4; ++i)
            cin >> a[i];
    }

    bool operator==(const state &s2) const
    {
        for (int i = 0; i < 4; ++i)
        {
            if (a[i] != s2.a[i])
                return false;
        }
        return true;
    }
};

bool visited[NMAX] = {false};

int moves[8][4] = {{1, 0, 0, 0},
                   {-1, 0, 0, 0},
                   {0, 1, 0, 0},
                   {0, -1, 0, 0},
                   {0, 0, 1, 0},
                   {0, 0, -1, 0},
                   {0, 0, 0, 1},
                   {0, 0, 0, -1}};

int mod(int x) { return ((x % 10) + 10) % 10; }

vector<state> next_states(state s)
{
    state ans[8];

    for (int i = 0; i < 8; ++i)
    {
        ans[i].depth = s.depth + 1;
        for (int j = 0; j < 4; ++j)
            ans[i].a[j] = mod(s.a[j] + moves[i][j]);
    }
    return vector<state>(ans, ans + 8);
}

int bfs(state start, state target)
{
    state        current;
    queue<state> q;

    if (visited[start.index()])
        return -1;

    q.push(start);

    while (not q.empty())
    {
        current = q.front();
        q.pop();

        if (current == target)
            return current.depth;

        for (state next : next_states(current))
        {
            if (not visited[next.index()])
            {
                visited[next.index()] = true;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(void)
{
    int   t, n;
    state start, target, forbidden;
    cin >> t;

    while (t--)
    {
        memset(visited, false, NMAX);
        start.cin_init();
        target.cin_init();

        cin >> n;

        while (n--)
        {
            forbidden.cin_init();
            visited[forbidden.index()] = true;
        }

        start.depth = 0;

        cout << bfs(start, target) << endl;
    }
    return 0;
}

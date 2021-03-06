#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void)
{
    int                         n, gi;
    multiset<int, greater<int>> ms;
    vector<int>                 a;
    cin >> n;

    for (int i = 0; i < n * n; ++i)
    {
        cin >> gi;
        ms.insert(gi);
    }

    while ((int)a.size() < n)
    {
        a.push_back(*ms.begin());
        ms.erase(ms.begin());

        for (int i = 0, nc = a.size() - 1; i < nc; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                auto it = ms.find(gcd(a[i], a[nc]));
                ms.erase(it);
            }
        }
    }

    for (auto ai : a)
        cout << ai << " ";
    cout << endl;

    return 0;
}

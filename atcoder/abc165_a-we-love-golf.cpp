#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b, k;
    cin >> k >> a >> b;
    while (a <= b)
    {
        if (a % k == 0)
        {
            cout << "OK" << endl;
            return 0;
        }
        a++;
    }
    cout << "NG" << endl;
    return 0;
}

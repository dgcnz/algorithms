#include <deque>
#include <iostream>

using namespace std;
using ll       = long long;
const int NMAX = 2 * 10e5 + 11;

int       n;
ll        high;
char      s[NMAX];
deque<ll> D, R;

int main(void)
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'D')
            D.push_back(i);
        else
            R.push_back(i);
    }

    high = n;

    while (D.size() and R.size())
    {
        ll fd = D.front();
        D.pop_front();
        ll fr = R.front();
        R.pop_front();

        if (fd < fr)
            D.push_back(high++);
        else
            R.push_back(high++);
    }

    if (D.size())
        cout << "D" << endl;
    else
        cout << "R" << endl;

    return 0;
}

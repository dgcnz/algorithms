#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a1, a2;
    cin >> a1 >> a2;

    int t = 0;

    if (a1 < a2)
        swap(a1, a2);

    while (a1 != 0)
    {
        int delta = a1 % 2 == 0 ? (a1 - 1) / 2 : a1 / 2;
        // dbg(a1, a2, delta);
        if (delta == 0)
        {
            t += a1 == 2;
            break;
        }

        t += delta;
        a1 -= 2 * delta;
        a2 += delta;
        swap(a1, a2);
    }

    cout << t << endl;
    return 0;
}

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
    int n;
    cin >> n;

    int const NMAX = 1e6;
    vi        freq(NMAX + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    for (int i = NMAX; i > 0; --i)
    {
        ll cnt = 0;
        for (int j = i; j <= NMAX; j += i)
            cnt += freq[j];

        if (cnt >= 2)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}

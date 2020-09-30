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

    int n, m;
    cin >> n;

    vector<bool> ans(n, 0);

    cout << "Q ", write(all(ans), " "), cout << endl;
    cin >> m;

    for (int i = 0; i < n; ++i)
    {
        int qans;

        ans[i] = 1;
        cout << "Q ", write(all(ans), " "), cout << endl;
        cin >> qans;
        if (qans <= m)
            ans[i] = 0;
        else
            m = qans;
    }
    cout << "A ", write(all(ans), " "), cout << endl;

    return 0;
}

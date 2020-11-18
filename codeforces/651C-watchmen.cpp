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
    auto fv = [](ii a, ii b) { return a.first < b.first; };
    auto sv = [](ii a, ii b) { return a.second < b.second; };

    int n;
    cin >> n;

    vector<ii> xy(n);
    for (auto &[x, y] : xy)
        cin >> x >> y;

    ll ans = 0;
    sort(all(xy), fv);

    int i = 0;
    while (i < n)
    {
        int j = i, cur = xy[i].first;
        while (j < n and cur == xy[j].first)
            ++j;

        ll k = j - i;
        ans += (k * (k - 1)) / 2;
        i = j;
    }

    // last

    i = 0;
    sort(all(xy), sv);
    while (i < n)
    {
        int j = i, cur = xy[i].second;
        while (j < n and cur == xy[j].second)
            ++j;

        ll k = j - i;
        ans += (k * (k - 1)) / 2;
        i = j;
    }

    i = 0;
    sort(all(xy));
    while (i < n)
    {
        int j   = i;
        ii  cur = xy[i];
        while (j < n and cur == xy[j])
            ++j;

        ll k = j - i;
        ans -= (k * (k - 1)) / 2;
        i = j;
    }

    cout << ans << endl;
    return 0;
}

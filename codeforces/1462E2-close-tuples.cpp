/** @file
 * @date                2020-12-15
 * @url                 https://codeforces.com/contest/1462/problem/E1
 * @tags                sorting, combinatorics, binary_search
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         3
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Assume a $a$ is sorted non-decreasingly.
 *
 * To count all the sequences ($a_{i_1}, a_{i_2}, ..., a_{i_m}$, assume $a_{i_j}
 * \leq a_{i_{j + 1}}$) that satisfy the given condition:
 * 1. Fix the maximum value, $a_{i_m}$.
 * 2. Find the minimum $a_{i_1}$ such that the condition ($a_{i_m} - a_{i_1}
 * \leq k$) holds.
 * 3. Compute the number of ways to pick $m-1$ elements from $i_m - i_1$.
 *
 * @endidea
 */
#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(x) x
#define assert(x) (void)0
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

template <typename T1, typename T2>
T1 binpow(T1 base, T2 exp)
{
    T1 ans = 1;
    while (exp > 0)
    {
        if (exp & 1)
            ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;
}

template <int M>
class ModInt
{
    using ll   = long long;
    using mint = ModInt<M>;
    ll x;

  public:
    static const int                MOD = M;
    inline static std::vector<mint> inv{};

    ModInt(ll x) : x(x) {}
    ModInt() : x(0) {}
    ModInt(mint const &y) : x(y.v()) {}
    explicit operator ll() const { return v(); }
    ll       v(void) const { return (this->x + M) % M; }
    mint &   operator=(mint const &y)
    {
        this->x = y.v();
        return *this;
    }
    mint &operator=(ll const &y) { return this->operator=(mint(y)); }
    mint &operator+=(mint const &y) { return this->operator=(operator+(y)); }
    mint &operator-=(mint const &y) { return this->operator=(operator-(y)); }
    mint &operator*=(mint const &y) { return this->operator=(operator*(y)); }
    mint  operator+(mint const &y) const { return (v() + y.v()) % M; }
    mint  operator+(ll const &y) const { return this->operator+(mint(y)); }
    mint  operator-(mint const &y) const { return (v() - y.v()) % M; }
    mint  operator-(ll const &y) const { return this->operator-(mint(y)); }
    mint  operator*(mint const &y) const { return (v() * y.v()) % M; }
    mint  operator*(ll const &y) const { return this->operator*(mint(y)); }
    mint operator/(mint const &y) const { return this->operator*(y.inverse()); }

    // Precompute len inverses
    static void precompute_inverses(int len)
    {
        assert(len < 1e8 and len >= 2);

        int len0 = inv.size();
        inv.resize(std::max(int(inv.size()), len), 0);
        if (len0 == 0)
            inv[1] = 1, len0 = 2;
        for (int i = len0; i < len; ++i)
            inv[i] = MOD - ll(inv[MOD % i] * (MOD / i));
    }
    mint        inverse(void) const { return binpow(*this, MOD - 2); }
    static mint inverse(ll x)
    {
        assert(x > 0);
        if (x < ll(inv.size()))
            return inv[x];
        return binpow(mint(x), MOD - 2);
    }
};

template <int MOD>
std::vector<ModInt<MOD>> factorials(int len)
{
    assert(len > 0);
    std::vector<ModInt<MOD>> ans(len);
    ans[0] = 1;
    for (int i = 1; i < len; i++)
        ans[i] = ans[i - 1] * i;
    return ans;
}

template <int MOD>
std::vector<ModInt<MOD>> inverse_factorials(int len)
{
    using mint = ModInt<MOD>;
    assert(len > 0);

    mint::precompute_inverses(len);
    std::vector<mint> inv_fact(len);

    inv_fact[0] = 1;
    for (int i = 1; i < len; i++)
        inv_fact[i] = inv_fact[i - 1] * mint::inverse(i);
    return inv_fact;
}

template <int NMAX, int MOD>
struct Combinations
{
    using mint = ModInt<MOD>;
    std::vector<mint> fact, inv_fact;

    Combinations(void)
    {
        fact     = factorials<MOD>(NMAX + 1);
        inv_fact = inverse_factorials<MOD>(NMAX + 1);
    }

    mint C(int n, int k) const
    {
        assert(n < NMAX);
        if (k > n or k < 0)
            return 0;
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }

    mint factorial(int n)
    {
        assert(fact.size() > n);
        return fact[n];
    }

    mint inverse_factorial(int n)
    {
        assert(inv_fact.size() > n);
        return inv_fact[n];
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int const MOD  = 1e9 + 7;
    int const NMAX = 2e5 + 11;
    using mint     = ModInt<MOD>;
    Combinations<NMAX, MOD> comb;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vi a(n);
        read_n(begin(a), n);
        sort(all(a));

        mint ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = distance(begin(a), lower_bound(all(a), a[i] - k));
            ans += comb.C(i - j, m - 1);
        }
        cout << ll(ans) << endl;
    }
    return 0;
}

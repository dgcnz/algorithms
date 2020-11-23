---
layout: post
mathjax: true
title: 1715 Creating Strings Ii
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

```cpp
{% raw %}
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
template <long long M, typename T = long long>
class NumMod
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    using NM = NumMod<M, T>;
    T x;
  public:
    static const ll MOD = M;
    NumMod(T x) : x(x) {}
    NumMod() : x(0) {}
    NumMod(NM const &y) : x(y.v()) {}
    explicit operator T() const { return x; }
    T v(void) const { return (this->x + M) % M; }
    NM & operator=(NM const &y)
    {
        this->x = y.v();
        return *this;
    }
    NM &operator=(T const &y) { return this->operator=(NM(y)); }
    NM &operator+=(NM const &y) { return this->operator=(operator+(y)); }
    NM &operator-=(NM const &y) { return this->operator=(operator-(y)); }
    NM &operator*=(NM const &y) { return this->operator=(operator*(y)); }
    NM operator+(NM const &y) const { return (v() + y.v()) % M; }
    NM operator+(T const &y) const { return this->operator+(NM(y)); }
    NM operator-(NM const &y) const { return (v() - y.v()) % M; }
    NM operator-(T const &y) const { return this->operator-(NM(y)); }
    NM operator*(NM const &y) const { return (v() * y.v()) % M; }
    NM operator*(T const &y) const { return this->operator*(NM(y)); }
    NM operator/(NM const &y) const { return this->operator*(inverse(y)); }
};
int const NMAX = 1e6 + 11;
int const MOD = 1e9 + 7;
using NM = NumMod<MOD, ll>;
NM fact[NMAX];
void precompute_fact(void)
{
    fact[0] = 1;
    for (int i = 1; i < NMAX; ++i)
        fact[i] = fact[i - 1] * i;
}
template <typename T>
T binpow(T a, ll b)
{
    T ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
NM inverse(NM const &y) { return binpow(y, y.MOD - 2); }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    vi freq(26, 0);
    cin >> s;
    for (char c : s)
        freq[c - 'a']++;
    precompute_fact();
    ll n = (int)s.size();
    vector<NM> rep(26);
    transform(freq.begin(), freq.end(), rep.begin(), [](auto cnt) { return fact[cnt]; });
    cout << ll(fact[n] / accumulate(rep.begin(), rep.end(), NM(1), multiplies<NM>())) << endl;
    return 0;
}

{% endraw %}
```
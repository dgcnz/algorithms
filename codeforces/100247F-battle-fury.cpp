#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll        = long long;
using predicate = function<bool(ll)>;
using vll       = vector<ll>;

ll  n, p, q;
vll a;

// first true in [false, false, ... true, true...]
ll binary_search(ll lo, ll hi, predicate p)
{
    while (lo < hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (p(mid) == true)
            hi = mid;
        else
            lo = mid + 1;
    }
    if (p(lo) == false)
        return -1; // p(x) is false for all x
    return lo;
}

// Note that one can think of direct_hits with damage p as side_hits with damage
// q with an additional (p - q).
//      damage(i) = total_hits * q + hits(i) * (p - q)
//
// Now, suppose we can kill all monsters with x hits. One can subtract to each
// monster the side damage that they will anyways have and for the remaining
// life polls count the number, x', of hits necessary to kill each of them
// independently. If x' > x then it's a contradiction and x is not enough to
// kill the n monsters.
//
//      x' = sum {ceil(ai'/ p') | i <- [1,2..n], let ai' = ai - x * q, let p' =
//                  (p - q)}
//
// In the case of p == q, to avoid division by 0:
//      x' = ceil(maximum a / p)

bool hits_suffice(ll x)
{
    ll total_hits;
    if (p == q)
        total_hits = (*max_element(a.begin(), a.end()) + p - 1) / p;
    else
        total_hits =
            accumulate(a.begin(), a.end(), (ll)0, [x](ll acc, ll ai) -> ll {
                ll ai_prime = ai - x * q;
                ll p_prime  = p - q;
                return acc + max((ll)0, (ai_prime + p_prime - 1) / p_prime);
            });
    return x >= total_hits;
}

int main(void)
{
    cin >> n >> p >> q;
    a = vll(n);
    for (auto &x : a)
        cin >> x;
    cout << binary_search(0, 1e9 + 11, hits_suffice) << endl;
    return 0;
}

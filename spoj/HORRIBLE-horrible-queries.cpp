/** @file
 * @date                2020-04-04
 * @url                 https://www.spoj.com/problems/HORRIBLE/
 * @tags                data_structures, segment_tree, lazy_propagation
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           yes
 * @reading_time        -1
 * @thinking_time       -1
 * @coding_time         -1
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Standard range query, range update, Sum Segment Tree.
 * @endidea
 */

#include <cstring>
#include <iostream>

const int NMAX = 1e5 + 10;

using namespace std;
using ll = long long;

ll n, a[NMAX], seg[4 * NMAX], lazy[4 * NMAX];

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
        seg[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

// Computes current node and propagates change to lazy subtrees
void lazy_propagate(ll v, ll tl, ll tr, ll val)
{
    seg[v] += (tr - tl + 1) * val; // Apply changes
    if (tl != tr)                  // If non-leaf, propagate lazily to children
    {
        lazy[2 * v] += val;
        lazy[2 * v + 1] += val;
    }
    lazy[v] = 0; // Clear node
}

// [tl, tr] : tree's range
// [ql, qr] : query's range

void update(ll v, ll tl, ll tr, ll ql, ll qr, ll x)
{

    if (lazy[v] != 0) // Pending update. Propagate lazily on children.
        lazy_propagate(v, tl, tr, lazy[v]);

    if (ql > qr) // no overlap
        return;

    if (tl == ql and tr == qr) // complete overlap
        lazy_propagate(
            v, tl, tr, x); // Apply x to node, lazily propagate to children
    else                   // partial overlap
    {
        ll tm = (tl + tr) / 2;
        update(v * 2, tl, tm, ql, min(qr, tm), x);
        update(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr, x);

        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

ll query(ll v, ll tl, ll tr, ll ql, ll qr)
{
    if (lazy[v] != 0) // Pending update. Propagate on children.
        lazy_propagate(v, tl, tr, lazy[v]);

    if (ql > qr) // no overlap
        return 0;
    if (tl == ql and tr == qr) // complete overlap
        return seg[v];
    else // partial overlap
    {
        ll tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, ql, min(qr, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr);
    }
}

int main(void)
{
    ll t, q, type, l, r, x;
    cin >> t;

    while (t--)
    {
        cin >> n >> q;
        while (q--)
        {
            cin >> type >> l >> r;
            if (type)
                cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
            else
            {
                cin >> x;
                update(1, 0, n - 1, l - 1, r - 1, x);
            }
        }
        memset(seg, 0, 4 * NMAX * sizeof(ll));
        memset(lazy, 0, 4 * NMAX * sizeof(ll));
        memset(a, 0, n * sizeof(ll));
    }
    return 0;
}

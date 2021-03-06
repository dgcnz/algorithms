// STATUS: ACCEPTED
#include <cmath>
#include <iostream>

using namespace std;

int time_spent(int x, int d) { return x + (int)ceil((d * 1.0) / (x + 1)); }

int binary_search(int n, int d) {
  int l = 1;
  int h = d - 1;

  while (l <= h) {
    int mid1 = l + (h - l) / 3;
    int mid2 = h - (h - l) / 3;
    int ans1 = time_spent(mid1, d);
    int ans2 = time_spent(mid2, d);

    if (ans1 <= n or ans2 <= n)
      return 1;
    else {
      if (ans1 < ans2)
        h = mid2 - 1;
      else {
        l = mid1 + 1;
      }
    }
  }
  return -1;
}

bool solve(int n, int d) {
  if (d <= n or binary_search(n, d) != -1)
    return true;
  return false;
}

int main(void) {
  int T;

  cin >> T;

  while (T--) {
    int n, d;
    cin >> n >> d;
    if (solve(n, d))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

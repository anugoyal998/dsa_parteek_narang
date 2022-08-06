#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        if (a > 2 * b)
        {
            cout << "NO\n";
        }
        else
        {
            a %= 3, b %= 3;
            if (a < b)
                swap(a, b);
            if ((a == 2 && b == 1) || (a == b && b == 0))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
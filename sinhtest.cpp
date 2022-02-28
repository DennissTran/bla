#include <bits/stdc++.h>
using namespace std;
// Tên chýõng tr?nh
const string NAME = "";
const string NAME2 = "";
// S? test ki?m tra
const int NTEST = 300;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {return l + rng() % (r - l + 1);}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME2 + ".inp").c_str());
        int n = Rand(3, 10), p = Rand(1, n); inp << n << ' ' << p << '\n';
        int prv = 0;
        for (int i = 1; i <= p; i++) {
            int l = Rand(prv, (2 * n - 1) / (p - i + 2));
            int r = Rand(l, (2 * n - 1) / (p - i + 1));
            inp << l << ' ' << r << '\n';
            prv = r;
        }
        inp.close();
        system((NAME + ".exe").c_str());
        system((NAME + "_debug.exe").c_str());
        if (system(("fc " + NAME2 + ".out " + NAME2 + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}

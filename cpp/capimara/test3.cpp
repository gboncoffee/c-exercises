#include<bits/stdc++.h>

using namespace std;

long int getp10(long int x) {
    for (long int i = 0;; i++) {
        if (10 > x)
            return i;
        x = x / 10;
    }
}

int main() {
    long int n;
    cin >> n;
    long int p10 = getp10(n);
    long int t = pow(10, (p10 / 2));

    if (0 < p10 - 2) {
        for (long int i = n / (p10 - 2); n >= i; ++i) {
            string s = to_string(i);
            long int l_o2 = s.length() / 2;
            if (s.length() % 2 == 0) {
                if (s.substr(0, l_o2) == s.substr(l_o2, s.length() - 1)) {
                    t++;
                }
            }
        }
    }

    cout << t << endl;
}

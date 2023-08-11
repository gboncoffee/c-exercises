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
    long int t = 0;
    for (long int i = 1; n >= i; ++i) {
        long int p10 = getp10(i);
        if ((p10 + 1) % 2 == 0) {
            string s = to_string(i);
            if (s.substr(0, s.length() / 2) == s.substr(s.length() / 2, s.length() - 1)) {
                t++;
            }
        } else {
            i = i * 10;
        }
    }
    cout << t << endl;
}

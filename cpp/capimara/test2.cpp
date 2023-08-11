#include<bits/stdc++.h>

using namespace std;

int main() {
    long int n;
    long int t = 0;
    cin >> n;
    for (int i = 1; n >= i; ++i) {
        string s = to_string(i);
        int l_o2 = s.length() / 2;
        if (s.length() % 2 == 0) {
            if (s.substr(0, l_o2) == s.substr(l_o2, s.length() - 1)) {
                t++;
            } else {
                if (2 > l_o2) {
                    i += pow(10, lo2 - 1);
                }
            }
        } else {
            i = i * 10;
        }
    }
    cout << t << endl;
}

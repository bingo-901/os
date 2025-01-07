#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f, pf = 0, count = 0;

    cout << "\nEnter the length of reference string: ";
    cin >> n;

    int rs[n];
    cout << "\nEnter the reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> rs[i];
    }

    cout << "\nEnter the number of frames: ";
    cin >> f;

    int m[f];
    memset(m, -1, sizeof(m));

    cout << "\nThe Page Replacement Process is:\n";
    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            m[count++] = rs[i];
            pf++;
        }

        for (int j = 0; j < f; j++) {
            cout << "\t" << (m[j] == -1 ? "-" : to_string(m[j]));
        }

        if (!found) cout << "\tPF No. " << pf;
        cout << "\n";

        count %= f;
    }

    cout << "\nThe number of Page Faults using FIFO are: " << pf << "\n";
    return 0;
}

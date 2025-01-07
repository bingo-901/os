#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, f, pf = 0;
    cout << "Enter number of page references: ";
    cin >> m;

    vector<int> rs(m);
    cout << "Enter the reference string:\n";
    for (int i = 0; i < m; i++) cin >> rs[i];

    cout << "Enter the available number of frames: ";
    cin >> f;

    vector<int> a(f, -1), cntr(f, 0);
    cout << "\nThe Page Replacement Process is:\n";

    for (int i = 0; i < m; i++) {
        bool pageFound = false;

        for (int j = 0; j < f; j++) {
            if (rs[i] == a[j]) {
                cntr[j]++;
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            int min = 0;
            for (int k = 1; k < f; k++) {
                if (cntr[k] < cntr[min]) min = k;
            }

            a[min] = rs[i];
            cntr[min] = 1;
            pf++;
        }

        for (int j = 0; j < f; j++) {
            cout << "\t" << (a[j] == -1 ? "-" : to_string(a[j]));
        }

        if (!pageFound) cout << "\tPF No. " << pf;

        cout << endl;
    }

    cout << "\nTotal number of page faults: " << pf << endl;
    return 0;
}

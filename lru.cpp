#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, f, pf = 0, next = 1;
    cout << "Enter the length of the reference string: ";
    cin >> n;

    vector<int> rs(n), m(f), count(f, 0);
    cout << "Enter the reference string:\n";
    for (int i = 0; i < n; i++) cin >> rs[i];

    cout << "Enter the number of frames: ";
    cin >> f;

    m.assign(f, -1);

    cout << "\nPage Replacement Process (LRU):\n";
    for (int i = 0; i < n; i++) {
        int pageFound = -1;

        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                pageFound = j;
                count[j] = next++;
                break;
            }
        }

        if (pageFound == -1) {
            int lru = 0;
            for (int j = 1; j < f; j++) if (count[j] < count[lru]) lru = j;
            m[lru] = rs[i];
            count[lru] = next++;
            pf++;
        }

        for (int j = 0; j < f; j++) cout << (m[j] == -1 ? "-" : to_string(m[j])) << "\t";
        cout << (pageFound == -1 ? "PF No. " + to_string(pf) : "") << endl;
    }

    cout << "\nTotal page faults: " << pf << endl;
    return 0;
}

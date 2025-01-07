#include <iostream>
#include <vector>
using namespace std;

int main() {
    int ms, s, n, i = 0, j = 0, avl_partitions, intr = 0;
    float size;

    cout << "Enter size of memory: ";
    cin >> ms;
    cout << "Enter memory for OS: ";
    cin >> s;

    ms -= s;

    cout << "Enter number of partitions: ";
    cin >> n;

    size = (float)ms / n;

    cout << "The available size of each partition is " << size << endl;

    avl_partitions = n;
    vector<int> ps(n);

    while (avl_partitions > 0) {
        cout << "Enter process size: ";
        cin >> ps[i];

        if (ps[i] <= size) {
            intr += size - ps[i];
            cout << "Process " << i << " is allocated to partition " << j << endl;
            i++;
            j++;
            avl_partitions--;
        } else {
            cout << "Process " << i << " is blocked" << endl;
            i++;
        }
    }

    cout << "Total fragmentation is " << intr << endl;

    return 0;
}

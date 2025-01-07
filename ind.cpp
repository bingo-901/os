#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    vector<int> ib(n), m(n);
    vector<vector<int>> b(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter index block for file " << i + 1 << ": ";
        cin >> ib[i];
        cout << "Enter number of blocks occupied by file " << i + 1 << ": ";
        cin >> m[i];

        cout << "Enter blocks of file " << i + 1 << ": ";
        for (int j = 0; j < m[i]; ++j) {
            int block;
            cin >> block;
            b[i].push_back(block);
        }
    }

    cout << "\nFile\tIndex\tLength\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "\t" << ib[i] << "\t" << m[i] << "\n";
    }

    cout << "Blocks occupied are:\n";
    for (int i = 0; i < n; ++i) {
        cout << "File no " << i + 1 << ":\n";
        for (int j = 0; j < m[i]; ++j) {
            cout << ib[i] << " ---> " << b[i][j] << "\n";
        }
    }

    return 0;
}

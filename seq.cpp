#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    vector<int> b(n), sb(n), t(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter number of blocks occupied by file " << i + 1 << ": ";
        cin >> b[i];
        cout << "Enter the starting block of file " << i + 1 << ": ";
        cin >> sb[i];
        t[i] = sb[i];
    }

    cout << "Filename\tStart block\tLength\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "\t" << t[i] << "\t" << b[i] << "\n";
    }

    cout << "Blocks occupied are:\n";
    for (int i = 0; i < n; ++i) {
        cout << "File no " << i + 1 << ": ";
        int start= sb[i];
        int end = start+b[i];
        for(int k=start;k<end;k++){
            cout<<k<<" ";
        }
        cout << "\n";
    }

    return 0;
}

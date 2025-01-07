#include <iostream>
using namespace std;

int main() {
    int totalMemory, osMemory, numProcesses, processSize[20];

    cout << "Enter total memory size: ";
    cin >> totalMemory;
    cout << "Enter number of processes: ";
    cin >> numProcesses;
    cout << "Enter memory for OS: ";
    cin >> osMemory;

    totalMemory -= osMemory;

    for (int i = 0; i < numProcesses; i++) {
        cout << "Enter size of process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    for (int i = 0; i < numProcesses; i++) {
        if (totalMemory >= processSize[i]) {
            cout << "Allocate memory to process " << i + 1 << endl;
            totalMemory -= processSize[i];
        } else {
            cout << "Process " << i + 1 << " is blocked" << endl;
        }
    }

    cout << "External Fragmentation is = " << totalMemory << endl;

    return 0;
}

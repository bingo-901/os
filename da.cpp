#include <iostream>
using namespace std;

struct Process {
    int max[10], al[10], need[10];
} p[10];

int main() {
    int n, r, tot[10], av[10], safeSeq[10], seqIndex = 0;
    
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> r;

    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << "\n";
        for (int j = 0; j < r; j++) {
            cout << "Max for resource " << j + 1 << ": ";
            cin >> p[i].max[j];
            cout << "Allocated for resource " << j + 1 << ": ";
            cin >> p[i].al[j];
            p[i].need[j] = p[i].max[j] - p[i].al[j];
        }
    }

    int totAllocated[10] = {0}; 
    for (int i = 0; i < r; i++) {
        cout << "Enter total value of resource " << i + 1 << ": ";
        cin >> tot[i];
        for (int j = 0; j < n; j++) totAllocated[i] += p[j].al[i];
        av[i] = tot[i] - totAllocated[i];
    }

    cout << "\nMax Allocated Needed Total Available\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t";
        for (int j = 0; j < r; j++) cout << p[i].max[j] << " ";
        cout << "\t";
        for (int j = 0; j < r; j++) cout << p[i].al[j] << " ";
        cout << "\t";
        for (int j = 0; j < r; j++) cout << p[i].need[j] << " ";
        cout << "\t";
        if (i == 0) {
            for (int j = 0; j < r; j++) cout << tot[j] << " ";
            for (int j = 0; j < r; j++) cout << av[j] << " ";
        }
        cout << endl;
    }

    int cn, cz, c = 0;
    cout << "\nAvail Before \t Avail After\n";
    for (int i = 0; i < n; i++) {
        cn = cz = 0;
        for (int j = 0; j < r; j++) {
            if (p[i].need[j] > av[j]) cn++;
            if (p[i].max[j] == 0) cz++;
        }
        if (cn == 0 && cz != r) {
            for (int j = 0; j < r; j++) {
                av[j] += p[i].al[j];
                p[i].max[j] = 0;
            }
            cout << "P" << i + 1 << "\t";
            for (int j = 0; j < r; j++) cout << av[j] << " ";
            safeSeq[seqIndex++] = i + 1;
            c++;
        }
    }

    if (c == n) {
        cout << "\nThe safe sequence is: ";
        for (int i = 0; i < n; i++) cout << "P" << safeSeq[i] << " ";
    } else {
        cout << "\nDeadlock occurred.";
    }

    return 0;
}

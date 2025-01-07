#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n;
    float sum_wt = 0.0, sum_tat = 0.0;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter the burst times:\n";
    for (int i = 0; i < n; ++i) {
        cin >> processes[i].bt;
    }

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.bt < b.bt;
    });

    processes[0].ct = processes[0].bt;
    for (int i = 1; i < n; ++i) {
        processes[i].ct = processes[i - 1].ct + processes[i].bt;
    }

    for (int i = 0; i < n; ++i) {
        processes[i].tat = processes[i].ct;
        processes[i].wt = processes[i].tat - processes[i].bt;
        sum_tat += processes[i].tat;
        sum_wt += processes[i].wt;
    }

    float avg_wt = sum_wt / n;
    float avg_tat = sum_tat / n;

    cout << "\nBT\tCT\tTAT\tWT\n";
    for (const auto& p : processes) {
        cout << p.bt << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << "\n";
    }

    cout << "\nAvg WT: " << avg_wt << "\tAvg TAT: " << avg_tat << "\n";

    return 0;
}

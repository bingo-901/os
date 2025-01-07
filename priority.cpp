#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Proc {
    int bt, pr, ct, tat, wt;
};

int main() {
    int n;
    float sum_wt = 0.0, sum_tat = 0.0;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<Proc> procs(n);

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; ++i) {
        cin >> procs[i].bt;
    }

    cout << "Enter priorities:\n";
    for (int i = 0; i < n; ++i) {
        cin >> procs[i].pr;
    }

    sort(procs.begin(), procs.end(), [](Proc a, Proc b) { return a.pr < b.pr; });

    procs[0].ct = procs[0].bt;
    for (int i = 1; i < n; ++i) {
        procs[i].ct = procs[i - 1].ct + procs[i].bt;
    }

    for (int i = 0; i < n; ++i) {
        procs[i].tat = procs[i].ct;
        procs[i].wt = procs[i].tat - procs[i].bt;
        sum_tat += procs[i].tat;
        sum_wt += procs[i].wt;
    }

    float avg_wt = sum_wt / n;
    float avg_tat = sum_tat / n;

    cout << "\nBT\tPR\tCT\tTAT\tWT\n";
    for (const auto& p : procs) {
        cout << p.bt << "\t" << p.pr << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << "\n";
    }

    cout << "\nAvg WT: " << avg_wt << "\tAvg TAT: " << avg_tat << "\n";

    return 0;
}

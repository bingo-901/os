#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Proc {
    string name;
    int bt, rt, ct, wt, tat;
};

int main() {
    int n, tq, time = 0, done = 0;
    float total_wt = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<Proc> procs(n);

    cout << "Enter process name and burst time for each process:\n";
    for (int i = 0; i < n; ++i) {
        cin >> procs[i].name >> procs[i].bt;
        procs[i].rt = procs[i].bt;
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    while (done < n) {
        for (int i = 0; i < n; ++i) {
            if (procs[i].rt > 0) {
                if (procs[i].rt > tq) {
                    time += tq;
                    procs[i].rt -= tq;
                } else {
                    time += procs[i].rt;
                    procs[i].rt = 0;
                    procs[i].ct = time;
                    procs[i].tat = procs[i].ct;
                    procs[i].wt = procs[i].tat - procs[i].bt;
                    total_wt += procs[i].wt;
                    done++;
                }
            }
        }
    }

    cout << "\nPN\tBT\tCT\tTAT\tWT\n";
    for (const auto& p : procs) {
        cout << p.name << "\t" << p.bt << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << "\n";
    }

    cout << "\nAvg WT: " << total_wt / n << "\n";
    return 0;
}

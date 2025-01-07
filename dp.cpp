#include <iostream>
#include <vector>
using namespace std;

class DeadlockSimulation {
private:
    vector<vector<int>> allocation, maximum, need;
    vector<int> available;
    vector<bool> finished;
    int processes, resources;

    bool checkSafeState() {
        bool progress;
        do {
            progress = false;
            for (int i = 0; i < processes; i++) {
                if (!finished[i]) {
                    bool canAllocate = true;
                    for (int j = 0; j < resources; j++) {
                        if (need[i][j] > available[j]) {
                            canAllocate = false;
                            break;
                        }
                    }
                    
                    if (canAllocate) {
                        for (int j = 0; j < resources; j++) {
                            available[j] += allocation[i][j];
                        }
                        finished[i] = true;
                        progress = true;
                    }
                }
            }
        } while (progress);

        // Check if all processes finished
        return all_of(finished.begin(), finished.end(), [](bool f) { return f; });
    }

public:
    DeadlockSimulation() {
        cout << "\nSIMULATION OF DEADLOCK PREVENTION\n";
        cout << "Enter number of processes and resources: ";
        cin >> processes >> resources;

        allocation = maximum = need = vector<vector<int>>(processes, vector<int>(resources));
        available = vector<int>(resources);
        finished = vector<bool>(processes, false);

        cout << "Enter allocation matrix:\n";
        for (auto &row : allocation) {
            for (int &x : row) cin >> x;
        }

        cout << "Enter maximum matrix:\n";
        for (auto &row : maximum) {
            for (int &x : row) cin >> x;
        }

        cout << "Enter available resources:\n";
        for (int &x : available) cin >> x;

        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                need[i][j] = maximum[i][j] - allocation[i][j];
            }
        }
    }

    void preventDeadlock() {
        if (!checkSafeState()) {
            for (int i = 0; i < processes; i++) {
                if (!finished[i]) {
                    cout << "\nTrying different prevention strategies for process " << i << ":\n";
                    
                    cout << "\n1. Breaking Mutual Exclusion:\n";
                    vector<int> tempAvail = available;
                    for (int j = 0; j < resources; j++) {
                        if (available[j] < need[i][j]) {
                            available[j] = need[i][j];
                        }
                    }
                    if (checkSafeState()) {
                        cout << "Deadlock prevented by providing additional resources\n";
                        return;
                    }
                    available = tempAvail;

                    cout << "\n2. Applying Preemption:\n";
                    for (int j = 0; j < resources; j++) {
                        if (available[j] < need[i][j]) {
                            available[j] += allocation[i][j];
                            allocation[i][j] = 0;
                        }
                    }
                    if (checkSafeState()) {
                        cout << "Deadlock prevented through preemption\n";
                        return;
                    }

                    cout << "\n3. Breaking Hold and Wait:\n";
                    for (int j = 0; j < resources; j++) {
                        if (available[j] < need[i][j]) {
                            available[j] = need[i][j];
                        }
                    }
                    if (checkSafeState()) {
                        cout << "Deadlock prevented by breaking hold and wait\n";
                        return;
                    }
                }
            }
        } else {
            cout << "\nSystem is already in safe state - no deadlock prevention needed.\n";
        }
    }
};

int main() {
    DeadlockSimulation sim;
    sim.preventDeadlock();
    return 0;
}
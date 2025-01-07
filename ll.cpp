#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct File {
    string fname;         
    int start;
    int size;
    vector<int> blocks;   
};

int main() {
    int n;

    cout << "Enter number of files: ";
    cin >> n;

    vector<File> files(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter file name: ";
        cin >> files[i].fname;
        cout << "Enter starting block: ";
        cin >> files[i].start;
        files[i].blocks.push_back(files[i].start); 

        cout << "Enter number of blocks: ";
        cin >> files[i].size;

        cout << "Enter block numbers: ";
        for (int j = 1; j <= files[i].size; j++) {
            int block;
            cin >> block;
            files[i].blocks.push_back(block);
        }
    }

    cout << "File\tStart\tSize\tBlocks\n";
    for (const auto& file : files) {
        cout << file.fname << "\t" << file.start << "\t" << file.size << "\t";
        for (size_t j = 0; j < file.blocks.size(); j++) {
            cout << file.blocks[j];
            if (j != file.blocks.size() - 1) cout << "-->";
        }
        cout << endl;
    }

    return 0;
}

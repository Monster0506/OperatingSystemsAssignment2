#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Please pass the input file" << endl;
        return 1;
    }

    string input_file = argv[1];
    ifstream in(input_file, ios::binary);
    if (!in.is_open()) {
        cerr << "Error: could not open " << input_file << endl;
        return 1;
    }

    int n, m;
    in.read((char*)(&n), sizeof(int));
    in.read((char*)(&m), sizeof(int));

    vector<int> avail(m);
    in.read((char*)(avail.data()), m * sizeof(int));

    vector<vector<int>> alloc(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        in.read((char*)(alloc[i].data()), m * sizeof(int));
    }

    vector<vector<int>> maxm(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        in.read((char*)(maxm[i].data()), m * sizeof(int));
    }

    cout << "n = " << n << ", m = " << m << endl;

    cout << "Available: ";
    for (int j = 0; j < m; j++) cout << avail[j] << " ";
    cout << endl;

    cout << "\nAllocation:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << alloc[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMax:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maxm[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<vector<int>> need(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = maxm[i][j] - alloc[i][j];
        }
    }

    vector<bool> finish(n, false);
    vector<int> safeSeq;

    for (int count = 0; count < n; count++) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[p][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < m; j++) avail[j] += alloc[p][j];
                    finish[p] = true;
                    safeSeq.push_back(p);
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    bool safe = true;
    for (bool f : finish)
        if (!f) safe = false;

    return 0;
}

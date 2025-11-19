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
    return 0;
}

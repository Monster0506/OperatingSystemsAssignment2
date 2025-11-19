#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Please pass the input and output files" << endl;
        return 1;
    }
    char* input_file = argv[1];
    char* output_file = argv[2];
    ifstream f(input_file);
    if (!f.is_open()) {
        cerr << "Error: could not open " << input_file << endl;
        return 1;
    }

    int n, m;
    f >> n >> m;

    vector<int> total(m);
    for (int j = 0; j < m; j++) {
        f >> total[j];
    }
    string label;
    f >> label;
    vector<vector<int>> alloc(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f >> alloc[i][j];
        }
    }

    f >> label;
    vector<vector<int>> maxm(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f >> maxm[i][j];
        }
    }

    f.close();

    ofstream out(output_file, ios::binary);
    if (!out.is_open()) {
        cerr << "Error: could not create " << output_file << endl;
        return 1;
    }

    out.write((char*)(&n), sizeof(int));
    out.write((char*)(&m), sizeof(int));

    out.write((char*)(total.data()), m * sizeof(int));

    for (int i = 0; i < n; i++) {
        out.write((char*)(alloc[i].data()), m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        out.write((char*)(maxm[i].data()), m * sizeof(int));
    }

    out.close();

    cout << "Serialization successful!" << endl;
    cout << "Created binary file: " << output_file << endl;

    return 0;
}

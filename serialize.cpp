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

    return 0;
}

#include <fstream>
#include <iostream>
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

    return 0;
}

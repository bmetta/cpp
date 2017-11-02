#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
  if(argc < 2) {
    cout << "usage: ./a.out read_file" << endl;
    return -1;
  }

  ofstream out_file(argv[1], ios::out);
  // open the file
  //out_file.open(argv[1], ios::out); // ios::out is default for ofstream
  if(!out_file.is_open()) {
    cout << "unable to open file: " << argv[1] << endl;
    return -1;
  }

  // write to the file
  out_file << "this first line\n";
  out_file << "this second line\n";

  // closing the file
  out_file.close();

  return 0;
}

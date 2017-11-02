#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
  if(argc < 2) {
    cout << "usage: ./a.out read_file" << endl;
    return -1;
  }

  ifstream in_file/*(argv[1], ios::in)*/;
  // open the file
  in_file.open(argv[1], ios::in); // ios::out is default for ifstream
  if(!in_file.is_open()) {
    cout << "unable to open file: " << argv[1] << endl;
    return -1;
  }

  // read the file
  int32_t i = 0;
  string line;
  while(getline(in_file, line)) {
    i++;
    cout << i << " " << line << endl;
  }

  // closing the file
  in_file.close();

  return 0;
}

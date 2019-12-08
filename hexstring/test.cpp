#include <iostream>
#include <string>
#include "hexstring.h"

using namespace std;

int main(int argc, char* argv[]){
  hexstring::test();
  if(argc < 2){
    cout << argv[0] << " hexstring" << endl;
    return 0;
  }
  hexstring s = string(argv[1]);
  hexstring s2 = s.reverse();
  cout << (string)s2 << endl;
  return 0;
}


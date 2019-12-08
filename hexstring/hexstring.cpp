#include <cassert>
#include <string>
#include "hexstring.h"

using namespace std;

bool iseven(int n){
  return n%2==0;
}

bool ishexchar(char ch){
  return ('0' <= ch && ch <= '9') || 
	 ('a' <= ch && ch <= 'f') ||
	 ('A' <= ch && ch <= 'F');
}

hexstring::hexstring(){}

hexstring::hexstring(const std::string& stdstr):str(stdstr){
  assert(iseven(stdstr.size()));
  for(string::iterator it = str.begin(); it != str.end(); it++)
    assert(ishexchar(*it));
}

hexstring& hexstring::operator=(const hexstring& hs){
  this->str = hs.str;
  return *this;
}

hexstring hexstring::reverse() const {
  string ret;
  const int N = str.size();
  ret.resize(N);
  for(int i=0; i<N; i+=2){
    ret[i+0] = str[N-1-1-i];
    ret[i+1] = str[N-1-0-i];
  }
  return ret;
}

hexstring::operator std::string() const {
  return str;
}

void hexstring::test(){
  assert(iseven(0));
  assert(!iseven(1));
  assert(iseven(2));

  string s0;
  hexstring hs0 = s0;
  assert((string)hs0 == string());

  string s2 = "ab";
  hexstring hs2 = s2;
  hs2 = hs2.reverse();
  assert((string)hs2 == string("ab"));

  string s4 = "abcd";
  hexstring hs4 = s4;
  hs4 = hs4.reverse();
  assert((string)hs4 == string("cdab"));
}


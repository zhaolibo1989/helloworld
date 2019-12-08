#ifndef hexstring_h
#define hexstring_h

#include <string>

class hexstring
{
  std::string str;
public:
  hexstring();
  hexstring(const std::string& stdstr);
  hexstring& operator=(const hexstring& hs);
  hexstring reverse() const;
  operator std::string() const;
  static void test();
};

#endif

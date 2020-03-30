#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace ranae::str {
  
  std::string fromws(const wchar_t *ws);

  void tows(const char* mbs, wchar_t* wcs, size_t wcsLen);

  template <size_t N>
  void tows(const char* mbs, wchar_t (&wcs)[N]) {
    return tows(mbs, wcs, N);
  }
  
  inline void format1(std::stringstream&) { }

  template<typename... Tx>
  void format1(std::stringstream& str, const wchar_t *arg, const Tx&... args) {
    str << fromws(arg);
    format1(str, args...);
  }

  template<typename T, typename... Tx>
  void format1(std::stringstream& str, const T& arg, const Tx&... args) {
    str << arg;
    format1(str, args...);
  }
  
  template<typename... Args>
  std::string format(const Args&... args) {
    std::stringstream stream;
    format1(stream, args...);
    return stream.str();
  }
  
}

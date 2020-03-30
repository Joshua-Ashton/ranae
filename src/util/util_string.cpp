#include "util_string.h"

#include <codecvt>
#include <locale>

namespace ranae::str {

  std::string fromws(const wchar_t *ws) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;

    return utf8_conv.to_bytes(ws);
  }

}

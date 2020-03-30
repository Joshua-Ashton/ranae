#include "util_env.h"
#include "util_win32.h"

namespace ranae::env {

  std::string getExePath() {
    std::vector<WCHAR> exePath;
    exePath.resize(MAX_PATH + 1);

    DWORD len = ::GetModuleFileNameW(NULL, exePath.data(), MAX_PATH);
    exePath.resize(len);

    return str::fromws(exePath.data());
  }

}
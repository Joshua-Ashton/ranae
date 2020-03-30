#pragma once

#include "../src/util/util_defer.h"
#include "../src/util/util_string.h"
#include "../src/util/log/log.h"

#define check(x) if (VkResult result = x) { Logger::err(str::format( #x ": failed, got result ", result)); return; }
#include "lib.hpp"

#define FMTLOG_HEADER_ONLY
#include <fmtlog/fmtlog.h>

#include "config.h"

void lib::hello_from_lib() { FMTLOG(fmtlog::INF, "Hello from '{}', version: '{}'", PROJECT_NAME, PROJECT_VERSION); }

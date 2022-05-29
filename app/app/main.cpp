#define FMTLOG_HEADER_ONLY
#include <fmtlog/fmtlog.h>

#include "config.h"

#include <lib/lib.hpp>

int main(int argc, char* argv[])
{
    FMTLOG(fmtlog::INF, "Hello from '{}', version: '{}'", PROJECT_NAME, PROJECT_VERSION);
    lib::hello_from_lib();

    return 0;
}

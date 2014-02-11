// Copyright (c) 2014 Eugene Zhuk.
// Use of this source code is governed by the MIT license that can be found
// in the LICENSE file.

#include "spawn/spawn.h"

#if defined(__APPLE__)
// On OS X shared libraries and bundles don't have direct access to environ,
// which is only available to ld(1) when a complete program is being linked.
// Although the environment routines are still available, the _NSGetEnviron()
// function needs to be used if direct access to environ is required.
#include <crt_externs.h>
char ** getenviron(void) { return * _NSGetEnviron(); }
#else
extern "C" char ** environ;
char ** getenviron(void) { return environ; }
#endif


int spawn(std::string const & path, pid_t * pid)
{
    char * argv[] = {
        const_cast<char *>(path.c_str()),
        nullptr
    };

    return posix_spawn(pid, path.c_str(), nullptr, nullptr, argv,
        getenviron());
}

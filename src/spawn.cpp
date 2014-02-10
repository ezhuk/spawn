// Copyright (c) 2014 Eugene Zhuk.
// Use of this source code is governed by the MIT license that can be found
// in the LICENSE file.

#include "spawn/spawn.h"


extern char ** environ;


int spawn(std::string const & path)
{
    pid_t pid = 0;
    char * argv[] = {
        const_cast<char *>(path.c_str()),
        nullptr
    };

    return posix_spawn(&pid, path.c_str(), nullptr, nullptr, argv, environ);
}

// Copyright (c) 2014 Eugene Zhuk.
// Use of this source code is governed by the MIT license that can be found
// in the LICENSE file.

#pragma once

#include <spawn.h>
#include <unistd.h>

#include <string>

// Spawns a new process.
int spawn(std::string const & path, pid_t * pid);

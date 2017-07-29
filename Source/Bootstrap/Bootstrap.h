/*
    Initial author: Convery (tcn@ayria.se)
    Started: 30-07-2017
    License: MIT
    Notes:
        Forward declarations for the bootstrap functions we'll call.
*/

#pragma once
#include "../Stdinclude.h"

namespace Bootstrap
{
    // The type of process we'll inject into.
    enum class Processtype : uint8_t
    {
        INVALID = 0,
        PE32_NATIVE = 1,
        PE64_NATIVE = 2,
        PE_MANAGED = 3,
        ELF32_NATIVE = 4,
        ELF64_NATIVE = 5,
    };

    // Analyze a binary to get process information.
    Processtype Analyzetarget(const char *Targetpath);

    // Create a new process, either the target or another bootstrap.
    void *Spawnprocess(const char *Targetpath, Processtype Targettype);

    // Inject a specified module into the spawned process.
    bool Injectmodule(void *Targethandle, Processtype Targettype);
}

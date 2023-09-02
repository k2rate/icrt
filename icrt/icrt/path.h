#pragma once

#include <icrt/detail.h>
#include "string.h"

namespace icrt
{
    ICRT_INLINE const char *path_filename(const char *pszPath)
    {
        size_t len = icrt::strlen(pszPath);
        for (size_t i = len; i != (0); i--)
            if (pszPath[i] == '\\' || pszPath[i] == '/')
                return &pszPath[i + 1];

        return nullptr;
    }
} // namespace icrt::inl
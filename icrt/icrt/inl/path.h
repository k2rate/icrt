#pragma once

#include <icrt/detail.h>
#include "string.h"

namespace icrt::inl
{
    ICRT_FORCEINLINE const char *path_filename(const char *pszPath)
    {
        size_t len = icrt::inl::strlen(pszPath);
        for (size_t i = len; i != (0); i--)
            if (pszPath[i] == '\\' || pszPath[i] == '/')
                return &pszPath[i + 1];

        return nullptr;
    }
} // namespace icrt::inl
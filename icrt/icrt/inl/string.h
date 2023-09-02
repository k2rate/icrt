#pragma once

#include <icrt/detail.h>

namespace icrt
{
    namespace inl
    {
        ICRT_FORCEINLINE char *uitoa(unsigned int i, char *buf) // buf size 21
        {
            char *p = buf + (20);
            do
            {
                *--p = '0' + (i % 10);
                i /= (10);
            } while (i != 0);
            return p;
        }

        ICRT_FORCEINLINE void strcpy(char *to, const char *from)
        {
            for (; *to = *from; ++from, ++to)
                ;
        }

        ICRT_FORCEINLINE size_t strlen(const char *str)
        {
            const char *s = str;
            for (; *s; ++s)
                ;
            return (s - str);
        }

        ICRT_FORCEINLINE char *strcat(char *s, const char *append)
        {
            char *save = s;
            for (; *s; ++s)
                ;
            while (*s++ = *append++)
                ;
            return (save);
        }

        ICRT_FORCEINLINE void memset(void *dst0, int c0, size_t length)
        {
            unsigned char *ptr = (unsigned char *)dst0;
            for (size_t i = 0; i < length; i++)
                ptr[i] = (unsigned char)c0;
        }

        ICRT_FORCEINLINE size_t wcslen(const wchar_t *s)
        {
            const wchar_t *p = s;
            while (*p)
                p++;
            return p - s;
        }

        ICRT_FORCEINLINE int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n)
        {
            if (n == 0)
                return 0;
            do
            {
                if (*s1 != *s2++)
                {
                    return (*(const unsigned int *)s1 - *(const unsigned int *)--s2);
                }
                if (*s1++ == 0)
                    break;
            } while (--n != 0);
            return 0;
        }

        ICRT_FORCEINLINE wchar_t *wcsstr(const wchar_t *__restrict s, const wchar_t *__restrict find)
        {
            wchar_t c, sc;
            size_t len;

            if ((c = *find++) != L'\0')
            {
                len = icrt::inl::wcslen(find);
                do
                {
                    do
                    {
                        if ((sc = *s++) == L'\0')
                            return (wchar_t *)0;
                    } while (sc != c);
                } while (icrt::inl::wcsncmp(s, find, len) != 0);
                s--;
            }
            return ((wchar_t *)s);
        }

        ICRT_FORCEINLINE char *strstr(char *string, char *substring)
        {
            char *a, *b;
            b = substring;
            if (*b == 0)
            {
                return string;
            }
            for (; *string != 0; string += 1)
            {
                if (*string != *b)
                {
                    continue;
                }
                a = string;
                while (1)
                {
                    if (*b == 0)
                    {
                        return string;
                    }
                    if (*a++ != *b++)
                    {
                        break;
                    }
                }
                b = substring;
            }
            return (char *)0;
        }

        ICRT_FORCEINLINE void memcpy(void *kyda, const void *otkydova, size_t caunt)
        {
            char *to = (char *)kyda;
            const char *from = (char *)otkydova;

            for (size_t i = 0; i < caunt; i++)
                to[i] = from[i];
        }

        ICRT_FORCEINLINE char toupper(char c) { return (c >= 'a' && c <= 'z') ? c - (0x20) : c; }

        ICRT_FORCEINLINE int stricmp(const char *s1, const char *s2)
        {
            while (icrt::inl::toupper(*s1) == icrt::inl::toupper(*s2))
            {
                if (*s1 == 0)
                    return 0;
                s1++;
                s2++;
            }

            return icrt::inl::toupper(*(unsigned const char *)s1) - icrt::inl::toupper(*(unsigned const char *)(s2));
        }
    } // namespace inl

} // namespace icrt
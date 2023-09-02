#include <gtest/gtest.h>

#include <icrt/string.h>
#include <icrt/inl/string.h>

TEST(icrt, Strings)
{
    ASSERT_EQ(icrt::strlen("200"), 3);
    ASSERT_EQ(icrt::inl::strlen("200"), 3);

    ASSERT_TRUE(icrt::stricmp("hello", "HeLLo") == 0);
    ASSERT_TRUE(icrt::inl::stricmp("hello", "HeLLo") == 0);
   
    ASSERT_EQ(icrt::wcslen(L"Hello"), 5);
    ASSERT_EQ(icrt::inl::wcslen(L"Hello"), 5);
}
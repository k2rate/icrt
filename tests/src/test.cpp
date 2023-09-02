#include <gtest/gtest.h>

#include <icrt/string.h>
#include <icrt/inl/string.h>

#include <icrt/path.h>
#include <icrt/inl/path.h>

TEST(icrt, String)
{
    ASSERT_EQ(icrt::strlen("200"), 3);
    ASSERT_EQ(icrt::inl::strlen("200"), 3);

    ASSERT_TRUE(icrt::stricmp("hello", "HeLLo") == 0);
    ASSERT_TRUE(icrt::inl::stricmp("hello", "HeLLo") == 0);
   
    ASSERT_EQ(icrt::wcslen(L"Hello"), 5);
    ASSERT_EQ(icrt::inl::wcslen(L"Hello"), 5);
}

TEST(icrt, Path)
{
    const char* filename = nullptr;

    filename = icrt::path_filename("C:/Users/Default/text.txt");
    ASSERT_NE(filename, nullptr);
    ASSERT_TRUE(icrt::stricmp(filename, "text.txt") == 0);

    filename = icrt::inl::path_filename("C:\\Users\\Default\\text.txt");
    ASSERT_NE(filename, nullptr);
    ASSERT_TRUE(icrt::inl::stricmp(filename, "text.txt") == 0);
}
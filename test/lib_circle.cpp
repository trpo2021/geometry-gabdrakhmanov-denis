#include <iostream>
#include <string.h>
#include <wkt_check.h>

extern "C" {
#include <ctest.h>
}

CTEST(input_suite, correct_input_check) // 1
{
    const char* input_char = "circle(13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, wrong_figure_input_check) // 2
{
    const char* input_char = "cirkle(13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, wrong_coords_input_check) // 3
{
    const char* input_char = "circle(1314,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, wrong_right_bracket_input_check) // 4
{
    const char* input_char = "circle(13 14,8";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, wrong_left_bracket_input_check) // 5
{
    const char* input_char = "circle13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, extra_spaces_in_input) // 6
{
    const char* input_char = "circle (13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, letter_in_x) // 7
{
    const char* input_char = "circle(1a3 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, letter_in_y) // 8
{
    const char* input_char = "circle(13 1c4,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, letter_in_rad) // 9
{
    const char* input_char = "circle(13 14,8r)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, extra_space_before_figure) // 10
{
    const char* input_char = " circle(13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, extra_space_after_figure) // 11
{
    const char* input_char = "circle(13 14,8) ";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, figure_witout_parametres) // 12
{
    const char* input_char = "circle";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, parametres_witout_figure) // 13
{
    const char* input_char = "(13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, parameteres_without_x) // 14
{
    const char* input_char = "circle( 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, parameteres_without_y) // 15
{
    const char* input_char = "circle(13 ,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, parameteres_without_rad) // 16
{
    const char* input_char = "circle(13 14)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, float_x) // 17
{
    const char* input_char = "circle(1.3 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, float_y) // 18
{
    const char* input_char = "circle(13 1.4,8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, float_rad) // 19
{
    const char* input_char = "circle(13 14,0.8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, float_all) // 20
{
    const char* input_char = "circle(1.3 1.4,0.8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, negative_x) // 21
{
    const char* input_char = "circle(-13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_y) // 22
{
    const char* input_char = "circle(13 -14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_rad) // 23
{
    const char* input_char = "circle(13 14,-8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_x_extra_space) // 24
{
    const char* input_char = "circle(- 13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_y_extra_space) // 25
{
    const char* input_char = "circle(13 - 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_rad_extra_space) // 26
{
    const char* input_char = "circle(13 14,- 8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, no_left_bracket) // 27
{
    const char* input_char = "circle13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, no_right_bracket) // 28
{
    const char* input_char = "circle13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, no_comma) // 29
{
    const char* input_char = "circle(13 148)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, no_space) // 30
{
    const char* input_char = "circle(1314,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, too_big_values) // 31
{
    const char* input_char = "circle(131313131313 141414141414,88888888888)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, too_small_values) // 32
{
    const char* input_char = "circle(0.0000000013 0.0000000014,0.000000008)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}
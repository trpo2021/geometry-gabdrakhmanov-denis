#include <iostream>
#include <string.h>
#include <lib_circle.h>

extern "C" {
#include <ctest.h>
}

CTEST(suite, CorrectInputCheck)
{
   const char *CharFigure = "circle(13 14,8)";
   int length = strlen(CharFigure);
   const bool result = wkt_check(CharFigure, length);
   ASSERT_TRUE(result);
}

CTEST(suite, WrongFigureInputCheck)
{
   const char *CharFigure = "cirkle(13 14,8)";
   int length = strlen(CharFigure);
   const bool result = wkt_check(CharFigure, length);
   ASSERT_FALSE(result);
}

CTEST(suite, WrongCoordsInputCheck)
{
   const char *CharFigure = "circle(1314,8)";
   int length = strlen(CharFigure);
   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, WrongRightBrackerInputCheck)
{
   const char *CharFigure = "circle(13 14,8";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, WrongLeftBrackerInputCheck)
{
   const char *CharFigure = "circle13 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, ExtraSpacesInInput)
{
   const char *CharFigure = "circle (13 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, LetterX)
{
   const char *CharFigure = "circle(1a3 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, LetterY)
{
   const char *CharFigure = "circle(13 1c4,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, LetterRad)
{
   const char *CharFigure = "circle(13 14,8r)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, ExtraSpaceBeforeFigure)
{
   const char *CharFigure = " circle(13 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, ExtraSpaceAfterFigure)
{
   const char *CharFigure = "circle(13 14,8) ";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, FigureWithoutParametres)
{
   const char *CharFigure = "circle";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, ParametresWithoutFigure)
{
   const char *CharFigure = "(13 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, ParametresWithoutX)
{
   const char *CharFigure = "circle(14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, ParametresWithoutY)
{
   const char *CharFigure = "circle(13 ,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, ParametresWithoutRad)
{
   const char *CharFigure = "circle(13 14)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, floatX)
{
   const char *CharFigure = "circle(1.3 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_TRUE(result);
}

CTEST(suite, floatY)
{
   const char *CharFigure = "circle(13 1.4,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_TRUE(result);
}

CTEST(suite, floatRad)
{
   const char *CharFigure = "circle(13 14,0.8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_TRUE(result);
}

CTEST(suite, floatAll)
{
   const char *CharFigure = "circle(1.3 1.4,0.8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_TRUE(result);
}

CTEST(suite, negativeX)
{
   const char *CharFigure = "circle(-13 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_TRUE(result);
}

CTEST(suite, negativeY)
{
   const char *CharFigure = "circle(13 -14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_TRUE(result);
}

CTEST(suite, negativeRad)
{
   const char *CharFigure = "circle(13 14,-8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, NegativeXExtraSpace)
{
   const char *CharFigure = "circle(- 13 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, NegativeYExtraSpace)
{
   const char *CharFigure = "circle(13 - 14,8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}

CTEST(suite, NegativeRadExtraSpace)
{
   const char *CharFigure = "circle(13 14,- 8)";
   int length = strlen(CharFigure);

   const bool result = circle_wkt_check(CharFigure, length);

   ASSERT_FALSE(result);
}
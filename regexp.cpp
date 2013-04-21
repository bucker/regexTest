#include "regexp.h"

regexp::regexp()
{
    //ctor
}

regexp::~regexp()
{
    //dtor
}

// match: search regexp in text
int regexp::match(char *regexp, char *text)
{
   if (regexp[0] == '^')
      return matchhere(regexp+1, text);
   do {
      if (matchhere(regexp, text))
         return 1;
   } while (*text++ != '\0');
   return 0;
}

// matchhere: search regexp in the begining of text
int regexp::matchhere(char *regexp, char *text)
{
   if (regexp[0] == '\0')
      return 1;
   if (regexp[1] == '*')
      return matchstar(regexp[0], regexp+2, text);
   if (regexp[0] == '$' && regexp[1] == '\0')
      return *text == '\0';
   if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
      return matchhere(regexp+1, text+1);
   return 0;
}

// matchstar: search c*regexp in the beginning of text
int regexp::matchstar(int c, char *regexp, char *text)
{
   do {
      if (matchhere(regexp, text))
         return 1;
   } while (*text != '\0' && (*text++ == c || c == '.'));
   return 0;
}

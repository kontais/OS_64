/*
 * setlocale.c
 *
 * Часть стандарта C2011
 *
 * Функция устанавливает новую локаль
 *
 */

#include <locale.h>

// TODO: реализована только минимальная функциональность!

static const char *deflocale = "C";

char *setlocale(int category, const char *locale)
{
  if ((locale == NULL) || (!strncmp(deflocale, locale, 2)))
    return deflocale;
  else
    return NULL;
}
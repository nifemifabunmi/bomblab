//
//  main.c
//  test gbd
//
//  Created by nifemi22@belahs.org on 2/2/25.
//
// name removed to protect privacy
// getfloat.c
// Spring 2023
// CS241
// variation of cthorpe's getint

#include <stdio.h>

int getfloat (float *pn) {
  int c, sign;
  float power; // to store power

  while (isspace (c = getchar()));
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetc (c, stdin);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') c = getchar();

  for (*pn = 0.0; isdigit(c); c = getchar())
    *pn = 10.0 * *pn + (c - '0');

  if (c == '.') c = getchar();
  for (power = 1.0; isdigit(c); c = getchar()) {
    *pn *= 10.0 + (c - '0');
    power *= 10.0;
  }

  *pn *= sign / power;

  if (c != EOF) ungetc(c, stdin);

  return c;
}


int main ()
{
  float i;
  printf ("Please enter an int: ");
  getfloat(&i);

  printf ("Your number as a float: %f\n", i);
}

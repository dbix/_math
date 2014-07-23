//
//  numerics.h
//  Numerics
//
//  Created by Derek Bixler on 7/19/14.
//  Copyright (c) 2014 Derek Bixler. All rights reserved.
//

#include <math.h>
#include <stdbool.h>

#include "defines.h"
#include "gauleg18.h"

/* Utility functions */
int signbiti(int i);
int signbitf(float f);
int signbitd(double d);
int signbitld(long double ld);
double radian(double d, double m, double s);
unsigned long bit_length(unsigned long n);
unsigned long count_set_bits(unsigned long n);

/* Exponential, logarithmic, and power functions */
double __pow__(double a, double b);
double __exp__(double x);
double __ln__(double x);
double __log__(double x);

/* Factorial */
uint64_t __factorial__(int n);
double __lnfactorial__(int n);
double __binom_coeff__(int k, int n);

/* Trigonometric functions */
float __sin__(float z);
float __cos__(float z);
double __tan__(double z);
double __sec__(double z);
double __csc__(double z);
double __cot__(double z);

double __arcsin__(double z);
double __arccos__(double z);
double __arctan__(double z);
double __arcsec__(double z);
double __arccsc__(double z);
double __arccot__(double z);

/* Hyperbolic functions */
double __sinh__(double z);
double __cosh__(double z);
double __tanh__(double z);
double __sech__(double z);
double __csch__(double z);
double __coth__(double z);

double __arcsinh__(double z);
double __arccosh__(double z);
double __arctanh__(double z);
double __arcsech__(double z);
double __arccsch__(double z);
double __arccoth__(double z);

/* Special functions */

/* Gamma */
double __gamma__(double z);
double __lngamma__(double z);
double __qgamma__(double z);
double __pgamma__(double z);
double __invgamma__(double z);

/* Beta */
double __beta__(double z);
double __lnbeta__(double z);

/* Error function */
inline double __erf__(double x);
inline double __erfc__(double x);
inline double __inverf__(double p);
double __erfccheb__(double z);
double __inverfc__(double p);

/* Statistics functions */
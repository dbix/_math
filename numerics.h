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
#include "numtypes.h"

/* Exponential, logarithmic, and power functions */
double pow(double a, double b);
double exp(double x);
double ln(double x);
double log(double x);

/* Trigonometric functions */
float __sin(float z);
float __cos(float z);
double __sin__(double z);
double __cos__(double z);
double tan(double z);
double sec(double z);
double csc(double z);
double cot(double z);

double_t arcsin(double_t z);
double_t arccos(double_t z);
double_t arctan(double_t z);
double_t arcsec(double_t z);
double_t arccsc(double_t z);
double_t arccot(double_t z);

/* Hyperbolic functions */
double_t sinh(double_t z);
double_t cosh(double_t z);
double_t tanh(double_t z);
double_t sech(double_t z);
double_t csch(double_t z);
double_t coth(double_t z);

double_t arcsinh(double_t z);
double_t arccosh(double_t z);
double_t arctanh(double_t z);
double_t arcsech(double_t z);
double_t arccsch(double_t z);
double_t arccoth(double_t z);

/* Special functions */
double gamma(double z);
double lngamma(double z);
double qgamma(double z);
double pgamma(double z);
double invgamma(double z);
double beta(double z);
double lnbeta(double z);

/* Statistics functions */
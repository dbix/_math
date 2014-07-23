#include "numerics.h"

double __beta__(double z, double w) {
    /* Standard beta function */
    return exp(lngamma(z)+lngamma(w)-lngamma(z+w));
}

double __betainc__(double a, double b, double x) {
    /* Incomplete beta function */
    return 0.0;
}


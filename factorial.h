#include <math.h>
#include "drerror.h"

/* Factorial function using table */
static double factorial(const int n) {
    static double a[171];
    int i;
    static bool init = true;
    if (init) {
        init = false;
        a[0] = 1.0;
            for (i=1; i<171; i++) a[i] = i*a[i-1];
    }
    if (n < 0 || n > 170) {
        printf("factorial is out of range");
        exit(1);
    }
    return a[n];
}

/* Natural log of factorial function */
static double lnfactorial(const int n) {
    static const Int NTOP=2000;
    static double a[NTOP];
    static int init = 0;
    if (init == 1) {
        init = 0;
        for (int i=0; i<NTOP; i++) a[i] = lngamma(i+1.); 
    }
    if (n < 0) fprintf(stderr, "negative arg in lnfactorial"); exit(1);
    if (n < NTOP) return a[n];
    return lngamma(n+1.);
}

/* Binomial coefficient function, a.k.a. "n choose k" */
static double binom_coeff(const int k, const int n) {
    if (n < 0 || k < 0 || k < n) fprintf(stderr, 
        "bad args in binom_coeff(k,n\n)"); exit(1);
    if (n<171) return floor(0.5+factrl(n)/(factrl(k)*factrl(n-k))); 
    return floor(0.5+exp(factln(n)-factln(k)-factln(n-k)));
}

/* Standard beta function */
static double beta(const double z, const double w) {
    return exp(lngamma(z)+lngamma(w)-lngamma(z+w));
}


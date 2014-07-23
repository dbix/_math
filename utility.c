//
//  round.c
//  Numerics
//
//  Created by Derek Bixler on 7/20/14.
//  Copyright (c) 2014 Derek Bixler. All rights reserved.
//

#include "numerics.h"
#include <inttypes.h>
#include <float.h>

/* Degrees, minutes, seconds to radians: */
double radian(double d, double m, double s) {
    double P64800 = 4.8481368110953599358991410e-5;
    return( ((d*60.0 + m)*60.0 + s)*P64800 );
}

double round(double x) {
    double y, r;
    y = floor(x);
    r = x - y;      /* fractional part */
    if( r > 0.5 ) goto rndup;
    if( r == 0.5 ) {
        r = y - 2.0 * floor( 0.5 * y );
        if( r == 1.0 ) {
        rndup:
            y += 1.0;
        }
    }
    return y;
}

unsigned long bit_length(unsigned long n) {
    unsigned long len = 0;
    while (n != 0) {
        ++len;
        n >>= 1;
    }
    return len;
}

unsigned long count_set_bits(unsigned long n) {
    unsigned long count = 0;
    while (n != 0) {
        ++count;
        n &= n - 1; /* clear least significant bit */
    }
    return count;
}

int signbiti(int i) {
    union {
        int i;
        uint32_t ui;
    } u;
    u.i = i;
    return u.ui >> 31;
}

int signbitf(float f) {
    union {
        float f;
        uint32_t i;
    } u;
    u.f = f;
    return u.i >> 31;
}

int signbitd(double d) {
    union {
        double d;
        uint64_t i;
    } u;
    u.d = d;
    return u.i >> 63;
}

int signbitld(long double ld) {
    union {
        long double ld;
        unsigned long long ll;
    } u;
    u.ld = ld;
    return u.ll >> 63;
}
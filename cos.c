//
//  cos.c
//  Numerics
//
//  Created by Derek Bixler on 7/20/14.
//  Copyright (c) 2014 Derek Bixler. All rights reserved.
//

#include "numerics.h"

#define FACTORIAL(x) fact_table[x]
#define TABLE_LENGTH 25


static long double fact[TABLE_LENGTH] = {
    /* Table of factorials */
    1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0, 40320.0, 362880.0,
    3628800.0, 39916800.0, 479001600.0, 6227020800.0, 87178291200.0,
    1307674368000.0, 20922789888000.0, 355687428096000.0, 6402373705728000.0,
    121645100408832000.0, 2432902008176640000.0, 51090942171709440000.0,
    25852016738884976640000.0, 15511210043330985984000000.0
};

float __cos__(float z) {
    /* Calculate sin z using a Maclauren series:
     sin z = 1 - z^2/2! + z^4/4! - z^6/6! + ... */
    if (z == 0.0) {
        return 1.0;
    } else if (z == M_PI) {
        return -1.0;
    } else if (z == M_PI_3) {
        return 0.5;
    } else if (z == M_2PI_3) {
        return -0.5;
    } else if (z == M_PI_2) {
        return 0;
    } else {
        int i;
        double_t zcoef[24];
        zcoef[0] = 1;
        for (i=2; i<=23; i=i+2) {
            zcoef[i] = pow(z,i)/fact[i];
        }
        return zcoef[0] - zcoef[2] + zcoef[4] - zcoef[6] + zcoef[8]
            - zcoef[10] + zcoef[12] - zcoef[14] + zcoef[16] - zcoef[18]
            + zcoef[20] - zcoef[22];
    }
}
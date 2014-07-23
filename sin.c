//
//  sin.c
//  Numerics
//
//  Created by Derek Bixler on 7/19/14.
//  Copyright (c) 2014 Derek Bixler. All rights reserved.
//

#include "numerics.h"

static long double fact[25] = {
    /* Values of {0,1,..,25}! */
    1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0, 40320.0, 362880.0,
    3628800.0, 39916800.0, 479001600.0, 6227020800.0, 87178291200.0,
    1307674368000.0, 20922789888000.0, 355687428096000.0, 6402373705728000.0,
    121645100408832000.0, 2432902008176640000.0, 51090942171709440000.0,
    25852016738884976640000.0, 15511210043330985984000000.0
};

float __sin__(float z) {
    /* Calculate sin z using Maclauren series:
     sin z = z - z^3/3! + z^5/5! - z^7/7! + ... */
    if (z == 0.0 || z == M_PI) {
        return 0.0;
    } else if (z == M_PI_6 || z == M_5PI_6) {
        return 0.50;
    } else if (z == M_PI_2) {
        return 1.0;
    } else {
        int i;
        double zcoef[25];
        zcoef[1] = z;
        for (i=3; i<=23; i=i+2) {
            zcoef[i] = pow(z,i)/fact[i];
        }
        return zcoef[1] - zcoef[3] + zcoef[5] - zcoef[7] + zcoef[9]
            - zcoef[11] + zcoef[13] - zcoef[15] + zcoef[17] - zcoef[19]
            + zcoef[21] - zcoef[23];
    }
}

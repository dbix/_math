//
//  sin.c
//  Numerics
//
//  Created by Derek Bixler on 7/19/14.
//  Copyright (c) 2014 Derek Bixler. All rights reserved.
//

#include <float.h>

#include "numerics.h"
#include "defines.h"

#define TABLE_LENGTH 25

static long double fact[TABLE_LENGTH] =
{
    /* Values of {0,1,..,25}! */
    1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0, 40320.0, 362880.0,
    3628800.0, 39916800.0, 479001600.0, 6227020800.0, 87178291200.0,
    1307674368000.0, 20922789888000.0, 355687428096000.0, 6402373705728000.0,
    121645100408832000.0, 2432902008176640000.0, 51090942171709440000.0,
    25852016738884976640000.0, 15511210043330985984000000.0
};

float __sin(float z) {
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



/*sin.c*/

/*
 Cephes Math Library Release 2.8:  June, 2000
 Copyright 1985, 1995, 2000 by Stephen L. Moshier
 */

static double sincof[] = {
    1.58962301576546568060E-10,
    -2.50507477628578072866E-8,
    2.75573136213857245213E-6,
    -1.98412698295895385996E-4,
    8.33333333332211858878E-3,
    -1.66666666666666307295E-1,
};
static double coscof[6] = {
    -1.13585365213876817300E-11,
    2.08757008419747316778E-9,
    -2.75573141792967388112E-7,
    2.48015872888517045348E-5,
    -1.38888888888730564116E-3,
    4.16666666666665929218E-2,
};
static double DP1 =   7.85398125648498535156E-1;
static double DP2 =   3.77489470793079817668E-8;
static double DP3 =   2.69515142907905952645E-15;
//static double lossth = 1.073741824e9;
static double PIO4   =  7.85398163397448309616E-1;
extern double p1evl ( double, void *, int );
extern double floor ( double );
extern double ldexp ( double, int );
static double lossth = 1.073741824e17;

double polevl(double x, double coef[], int N) {
    double ans, *p;
    int i;
    p = coef;
    ans = *p++;
    i = N;
    do
        ans = ans*x + *p++;
    while(--i);
    return ans;
}

double __sin__(double x) {
    double y, z, zz;
    int j, sign;
    if( x == 0.0 )
        return x;
    if(isnan(x))
        return x;
    if(isinf(x))
      return INFINITY;
    sign = 1;
    if( x < 0 ) {
        x = -x;
        sign = -1;
    }
    if( x > lossth ) {
        return(0.0);
    }
    y = floor(x/PIO4);
    z = ldexp(y,-4);
    z = floor(z);
    z = y - ldexp(z, 4);
    j = z;
    if( j & 1 ) {
        j += 1;
        y += 1.0;
    }
    j = j & 07;
    if( j > 3) {
        sign = -sign;
        j -= 4;
    }
    z = ((x - y * DP1) - y * DP2) - y * DP3;
    zz = z * z;
    if( (j==1) || (j==2) ) {
        y = 1.0 - ldexp(zz,-1) + zz * zz * polevl( zz, coscof, 5 );
    } else {
        y = z  +  z * z * z * polevl( zz, sincof, 5 );
    }
    if(sign < 0) {
        y = -y;
    }
    return (float)y;
}

double __cos__(double x) {
    double y, z, zz;
    long i;
    int j, sign;
    
    if(isnan(x))
        return x;
    if(!isfinite(x))
      return 1.0/0.0;
    sign = 1;
    if( x < 0 )
        x = -x;
    if( x > lossth )
        return(0.0);
    y = floor(x/PIO4);
    z = ldexp( y, -4 );
    z = floor(z);
    z = y - ldexp( z, 4 );
    i = z;
    if( i & 1 ) {
        i += 1;
        y += 1.0;
    }
    j = i & 07;
    if( j > 3) {
        j -=4;
        sign = -sign;
    }
    if( j > 1 )
        sign = -sign;
    z = ((x - y * DP1) - y * DP2) - y * DP3;
    zz = z * z;
    if((j==1) || (j==2)) {
        y = z  +  z * z * z * polevl( zz, sincof, 5 );
    } else {
        y = 1.0 - ldexp(zz,-1) + zz * zz * polevl( zz, coscof, 5 );
    }
    if(sign < 0)
        y = -y;
    return(y);
}

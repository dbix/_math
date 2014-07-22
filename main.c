//
//  main.c
//  Numerics
//
//  Created by Derek Bixler on 7/19/14.
//  Copyright (c) 2014 Derek Bixler. All rights reserved.
//


#include <stdio.h>
#include <math.h>
#include <float.h>
#include "numerics.h"

#define rt3(x) pow((x), 1.0 / 3.0)
#define rt4(x) pow((x), 1.0 / 4.0)
#define rt5(x) pow((x), 1.0 / 5.0)
#define rt6(x) pow((x), 1.0 / 6.0)

//#include "numerics.h"

void params();

//int main(int argc, const char * argv[])
//{
//    params();
//    /* Test __sin__ against library function */
//    printf("sin(0.5)   = %.23f\n",   __sin__(0.5));
//    printf("sin(0.5)   = %.23f\n",   __sin  (0.5));
//    printf("sin(0.5)   = %.23f\n\n",   sin  (0.5));
//    
//    printf("sin(0.25)  = %.23f\n",   __sin__(0.25));
//    printf("sin(0.25)  = %.23f\n",   __sin  (0.25));
//    printf("sin(0.25)  = %.23f\n\n",   sin  (0.25));
//    
//    printf("sin(0.125) = %.23f\n",   __sin__(0.125));
//    printf("sin(0.125) = %.23f\n",   __sin  (0.125));
//    printf("sin(0.125) = %.23f\n\n",   sin  (0.125));
//    
//    printf("sin(pi/8)  = %.23f\n",   __sin__(M_PI/8));
//    printf("sin(pi/8)  = %.23f\n",   __sin  (M_PI/8));
//    printf("sin(pi/8)  = %.23f\n\n",   sin  (M_PI/8));
//    
//    printf("sin(pi/2)  = %.23f\n",   __sin__(M_PI_2));
//    printf("sin(pi/2)  = %.23f\n\n",   sin  (M_PI_2));
//    
//    printf("sin(pi/12) = %.23f\n",   __sin__(M_PI_12));
//    printf("sin(pi/12) = %.23f\n\n\n", sin  (M_PI_12));
//
//    
//    /* Test __cos__ against library function */
//    printf("cos(0.5)   = %.23f\n",   __cos__(0.5));
//    printf("cos(0.5)   = %.23f\n\n",   cos  (0.5));
//    
//    printf("cos(0.25)  = %.23f\n",   __cos__(0.25));
//    printf("cos(0.25)  = %.23f\n\n",   cos  (0.25));
//    
//    printf("cos(0.125) = %.23f\n",   __cos__(0.125));
//    printf("cos(0.125) = %.23f\n\n",   cos  (0.125));
//    
//    printf("cos(pi/8)  = %.23f\n",   __cos__(M_PI/8));
//    printf("cos(pi/8)  = %.23f\n\n",   cos  (M_PI/8));
//    
//    printf("cos(pi/2)  = %.23f\n",   __cos__(M_PI_2));
//    printf("cos(pi/2)  = %.23f\n\n",   cos  (M_PI_2));
//    
//    printf("cos(pi/12) = %.23f\n",   __cos__(M_PI_12));
//    printf("cos(pi/12) = %.23f\n",     cos  (M_PI_12));
//    
//    
//    /* Test signbit functions */
//    printf("Sign bit of int -1 is %d\n", signbiti(-1));
//    printf("Sign bit of int 23152 is %d\n", signbiti(23152));
//    printf("Sign bit of float -1.2352 is %d\n", signbitf((float)-1.2352));
//    printf("Sign bit of float -5213.2352 is %d\n", signbitf((float)-5213.2352));
//    printf("Sign bit of double 1.2352 is %d\n", signbitf((double)1.2352));
//    printf("Sign bit of double -5213.2352 is %d\n", signbitf((double)-5213.2352));
//    
//    float f = 5.2532;
//    union { int i; float f; } u;
//    u.f = f;
//    
//    printf("%f and %d", u.f, u.i);
//    
//    return 0;
//    
//}
//
//void params()
//{
//    printf ("#define DBL_EPSILON       % .16e\n", DBL_EPSILON);
//    printf ("#define SQRT_DBL_EPSILON  % .16e\n", sqrt (DBL_EPSILON));
//    printf ("#define ROOT3_DBL_EPSILON % .16e\n", rt3 (DBL_EPSILON));
//    printf ("#define ROOT4_DBL_EPSILON % .16e\n", rt4 (DBL_EPSILON));
//    printf ("#define ROOT5_DBL_EPSILON % .16e\n", rt5 (DBL_EPSILON));
//    printf ("#define ROOT6_DBL_EPSILON % .16e\n", rt6 (DBL_EPSILON));
//    printf ("#define LOG_DBL_EPSILON  (% .16e)\n", log (DBL_EPSILON));
//    printf ("\n");
//    
//    printf ("#define DBL_MIN       % .16e\n", DBL_MIN);
//    printf ("#define SQRT_DBL_MIN  % .16e\n", sqrt (DBL_MIN));
//    printf ("#define ROOT3_DBL_MIN % .16e\n", rt3 (DBL_MIN));
//    printf ("#define ROOT4_DBL_MIN % .16e\n", rt4 (DBL_MIN));
//    printf ("#define ROOT5_DBL_MIN % .16e\n", rt5 (DBL_MIN));
//    printf ("#define ROOT6_DBL_MIN % .16e\n", rt6 (DBL_MIN));
//    printf ("#define LOG_DBL_MIN  (% .16e)\n", log (DBL_MIN));
//    printf ("\n");
//    
//    printf ("#define DBL_MAX       % .16e\n", DBL_MAX);
//    printf ("#define SQRT_DBL_MAX  % .16e\n", sqrt (DBL_MAX));
//    printf ("#define ROOT3_DBL_MAX % .16e\n", rt3 (DBL_MAX));
//    printf ("#define ROOT4_DBL_MAX % .16e\n", rt4 (DBL_MAX));
//    printf ("#define ROOT5_DBL_MAX % .16e\n", rt5 (DBL_MAX));
//    printf ("#define ROOT6_DBL_MAX % .16e\n", rt6 (DBL_MAX));
//    printf ("#define LOG_DBL_MAX   % .16e\n", log (DBL_MAX));
//    printf ("\n");
//    
//    printf ("#define FLT_EPSILON       % .16e\n", FLT_EPSILON);
//    printf ("#define SQRT_FLT_EPSILON  % .16e\n", sqrt (FLT_EPSILON));
//    printf ("#define ROOT3_FLT_EPSILON % .16e\n", rt3 (FLT_EPSILON));
//    printf ("#define ROOT4_FLT_EPSILON % .16e\n", rt4 (FLT_EPSILON));
//    printf ("#define ROOT5_FLT_EPSILON % .16e\n", rt5 (FLT_EPSILON));
//    printf ("#define ROOT6_FLT_EPSILON % .16e\n", rt6 (FLT_EPSILON));
//    printf ("#define LOG_FLT_EPSILON  (% .16e)\n", log (FLT_EPSILON));
//    printf ("\n");
//    
//    printf ("#define FLT_MIN       % .16e\n", FLT_MIN);
//    printf ("#define SQRT_FLT_MIN  % .16e\n", sqrt (FLT_MIN));
//    printf ("#define ROOT3_FLT_MIN % .16e\n", rt3 (FLT_MIN));
//    printf ("#define ROOT4_FLT_MIN % .16e\n", rt4 (FLT_MIN));
//    printf ("#define ROOT5_FLT_MIN % .16e\n", rt5 (FLT_MIN));
//    printf ("#define ROOT6_FLT_MIN % .16e\n", rt6 (FLT_MIN));
//    printf ("#define LOG_FLT_MIN  (% .16e)\n", log (FLT_MIN));
//    printf ("\n");
//    
//    printf ("#define FLT_MAX       % .16e\n", FLT_MAX);
//    printf ("#define SQRT_FLT_MAX  % .16e\n", sqrt (FLT_MAX));
//    printf ("#define ROOT3_FLT_MAX % .16e\n", rt3 (FLT_MAX));
//    printf ("#define ROOT4_FLT_MAX % .16e\n", rt4 (FLT_MAX));
//    printf ("#define ROOT5_FLT_MAX % .16e\n", rt5 (FLT_MAX));
//    printf ("#define ROOT6_FLT_MAX % .16e\n", rt6 (FLT_MAX));
//    printf ("#define LOG_FLT_MAX   % .16e\n", log (FLT_MAX));
//    printf ("\n");
//    
//    printf ("#define SFLT_EPSILON       % .16e\n", SFLT_EPSILON);
//    printf ("#define SQRT_SFLT_EPSILON  % .16e\n", sqrt (SFLT_EPSILON));
//    printf ("#define ROOT3_SFLT_EPSILON % .16e\n", rt3 (SFLT_EPSILON));
//    printf ("#define ROOT4_SFLT_EPSILON % .16e\n", rt4 (SFLT_EPSILON));
//    printf ("#define ROOT5_SFLT_EPSILON % .16e\n", rt5 (SFLT_EPSILON));
//    printf ("#define ROOT6_SFLT_EPSILON % .16e\n", rt6 (SFLT_EPSILON));
//    printf ("#define LOG_SFLT_EPSILON  (% .16e)\n", log (SFLT_EPSILON));
//    printf ("\n");
//}


#include <math.h>
#include "gauleg18.h"

/* Constants */
#define ASWITCH 100

double __gamma__(double z) {
    /* Standard gamma function */
    return exp(__lngamma__(z));
}

double __lngamma__(double z) {
    /* Natural log of gamma function */
    int j;
    double x, tmp, y, ser;
    static const double cof[14] = {
        57.156235665862923500, -59.597960355475491200,  14.136097974741747100, 
       -0.4919138160976201990,  0.3399464998481188e-4,  0.4652362892704857e-4, 
       -0.9837447530487956e-4,  0.1580887032249124e-3, -0.2102644417241048e-3, 
        0.2174396181152126e-3, -0.1643181065367638e-3,  0.8441822398385274e-4, 
       -0.2619083840158140e-4,  0.3689918265953162e-5
    }; 
    if (z <= 0) 
        return NAN;
    y=x=z;
    tmp = x + 5.24218750000000000;
    tmp = (x+0.5) * log(tmp) - tmp;
    ser = 0.999999999999997092;
    for (j=0;j<14;j++) 
        ser += cof[j]/++y;
    return tmp + log(2.5066282746310005 * ser / x);
}

#include <math.h>
#include "drerror.h"
#include "gauleg18.h"

/* Macros */
#define MIN(x,y) ( (x)<(y)?(x):(y) )
#define MAX(x,y) ( (x)>(y)?(x):(y) )

/* Constants */
#define ASWITCH 100

/* Standard gamma function */
static double gamma(const double z) {
    return exp(lngamma(z));
}

/* Natural log of gamma function */
static double lngamma(const double z) {
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
        drerror("bad args in lngamma(z)\n");
    y=x=z;
    tmp = x+5.24218750000000000; 
    tmp = (x+0.5)*log(tmp)-tmp;
    ser = 0.999999999999997092;
    for (j=0;j<14;j++) 
        ser += cof[j]/++y;
    return tmp+log(2.5066282746310005*ser/x);
}

/* Incomplete gamma function P(a,x) */
static double incgammap(const double a, const double x) {
    if (x < 0.0 || a <= 0.0)            
        drerror("bad args in incgammap(a,x)\n");
    if (x == 0.0)                       
        return 0.0;
    else if ((Int)a >= ASWITCH)         
        return gammpapprox(a,x,1);
    else if (x < a+1.0)                 
        return gser(a,x);
    else
        return 1.0-incgammaq_cf(a,x); 
}

/* Incomplete gamma function Q(a,x) */
static double incgammaq(const double a, const double x) {
    if (x < 0.0 || a <= 0.0) 
        drerror("bad args in incgammap(a,x)\n");
    if (x == 0.0)               
        return 1.0;
    else if ((int)a >= ASWITCH) 
        return incgammap_approx(a,x,0);      
    else if (x < a+1.0)         
        return 1.0-incgamma_ser(a,x);
    else                        
        return incgammaq_cf(a,x);
}

/* Series representation */
static double incgammap_ser(const double a, const double x) {
    double sum,del,ap;
    gln=lngamma(a);
    ap=a;
    del=sum=1.0/a;
    for (;;) {
        ++ap;
        del *= x/ap;
        sum += del;
        if (fabs(del) < fabs(sum)*EPS) 
            return sum*exp(-x+a*log(x)-gln);
    }
}

/* Continued fraction representation */
static double incgammaq_cf(const double a, const double x) {
    int i;
    double an,b,c,d,del,h;
    gln=gammln(a);
    b=x+1.0-a;
    c=1.0/DBL_MIN;
    d=1.0/b;
    h=d;
    for (i=1;;i++) {
        an = -i*(i-a);
        b += 2.0;
        d = an*d+b;
        if (fabs(d) < FPMIN) d=FPMIN;
        c=b+an/c;
        if (fabs(c) < FPMIN) c=FPMIN;
        d=1.0/d;
        del=d*c;
        h *= del;
        if (fabs(del-1.0) <= EPS) break;
    }
    return exp(-x+a*log(x)-gln)*h;
}

/* Incomplete gamma function P(a,x) or Q(a,x); psig == 0 ? P(a,x) : Q(a,x) */
static double incgammap_approx(double a, double x, int psig) {
    int j;
    double xu,t,sum,ans;
    double a1 = a-1.0, lna1 = log(a1), sqrta1 = sqrt(a1);
    gln = lngamma(a);
    if (x > a1) xu = MAX(a1 + 11.5*sqrta1, x + 6.0*sqrta1); 
    else xu = MAX(0.,MIN(a1 - 7.5*sqrta1, x - 5.0*sqrta1)); 
    sum = 0;
    for (j=0; j < GAULEG18.NGAU; j++) {
        t = x + (xu-x)*GAULEG18.Y[j];
        sum += GAULEG18.W[j]*exp(-(t-a1)+a1*(log(t)-lna1));
    }
    ans = sum*(xu-x)*exp(a1*(lna1-1.)-gln);
    return (psig? (ans > 0.0? 1.0-ans : -ans) : (ans >= 0.0? ans : 1.0+ans));
}

/* Inverse incomplete gamma function using Halley's method */
static double inv_incgammap(double p, double a) {
    double x, err, t, u, pp, lna1, gln, afac, a1;
    a1 = a-1;
    gln = lngamma(a);
    if (a <= 0.) 
        drerror("a must be pos in invgammap");
    if (p >= 1.) 
        return MAX(100.,a + 100.*sqrt(a));
    if (p <= 0.) 
        return 0.0;
    if (a > 1.) {
        lna1=log(a1);
        afac = exp(a1*(lna1-1.)-gln);
        pp = (p < 0.5)? p : 1. - p;
        t = sqrt(-2.*log(pp));
        x = (2.30753+t*0.27061)/(1.+t*(0.99229+t*0.04481)) - t; 
        if (p < 0.5) 
            x = -x;
        x = MAX(1.e-3,a*pow(1.e-1./(9.*a)-x/(3.*sqrt(a)),3));
    } else {
        t = 1.0 - a*(0.253+a*0.12);
        if (p < t)
            x = pow(p/t,1./a);
        else 
            x = 1.-log(1.-(p-t)/(1.-t));
    }
    for (j=0;j<12;j++) {
        if (x <= 0.0) 
            return 0.0;
        err = incgammap(a,x) - p;
        if (a > 1.) 
            t = afac*exp(-(x-a1)+a1*(log(x)-lna1));
        else 
            t = exp(-x+a1*log(x)-gln);
        u = err/t;
        x -= (t = u/(1.-0.5*MIN(1.,u*((a-1.)/x - 1))));
        if (x <= 0.) 
            x = 0.5*(x + t);
        if (fabs(t) < DBL_EPSILON*x ) 
            break;
    }
    return x;
}

/* Factorial function using table */
static double factorial(const int n) {
    static double a[171];
    int i;
    static bool init = true;
    if (init) {
        init = false;
        a[0] = 1.;
            for (i=1;i<171;i++) a[i] = i*a[i-1];
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


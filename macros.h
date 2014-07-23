//
//  macros.h
//  Special Functions
//
//  Created by Derek Bixler on 6/29/14.
//  Copyright (c) 2014 Derek Bixler <dbixler@asu.edu>. All rights reserved.
//

#ifndef MACROS_H_
#define MACROS_H_

/* Number manipulation */
#define DEG_TO_RAD(x)                                                       \
(                                                                           \
    (x) * 57.29578                                                          \
)

#define RAD_TO_DEG(x)                                                       \
(                                                                           \
    (x) / 57.29578                                                          \
)

/* Numerical comparisons and queries */
#define IS_EVEN(n)                                                          \
(                                                                           \
    !(IS_ODD(n))                                                            \
)

#define IS_FINITE(x)                                                        \
(                                                                           \
      sizeof(x) == sizeof(float ) ? __inline_isfinitef((float )(x))         \
    : sizeof(x) == sizeof(double) ? __inline_isfinited((double)(x))         \
    : __inline_isfinitel((long double)(x))                                  \
)

#define IS_INF(x)                                                           \
(                                                                           \
    sizeof(x) == sizeof(float)  ? __inline_isinff((float)(x))               \
    : sizeof(x) == sizeof(double) ? __inline_isinfd((double)(x))            \
    : __inline_isinfl((long double)(x))                                     \
)

#define IS_NAN(x)                                                           \
(                                                                           \
    sizeof(x) == sizeof(float)  ? __inline_isnanf((float)(x))               \
    : sizeof(x) == sizeof(double) ? __inline_isnand((double)(x))            \
    : __inline_isnanl((long double)(x))                                     \
)

#define IS_NORMAL (x)                                                       \
(                                                                           \
    sizeof(x) == sizeof(float)  ? __inline_isnormalf((float)(x))            \
    : sizeof(x) == sizeof(double) ? __inline_isnormald((double)(x))         \
    : __inline_isnormall((long double)(x))                                  \
)

#define IS_ODD (n)                                                          \
(                                                                           \
    (n) & 1                                                                 \
)

#define SIGN_BIT(x)                                                         \
(                                                                           \
    sizeof(x) == sizeof(float)  ? __inline_signbitf((float)(x))  :          \
    sizeof(x) == sizeof(double) ? __inline_signbitd((double)(x)) :          \
    __inline_signbitl((long double)(x))                                     \
)

#define MIN(x,y)                                                            \
(                                                                           \
    (x)<(y)?(x):(y)                                                         \
)

#define MAX(x,y)                                                            \
(                                                                           \
    (x)>(y)?(x):(y)                                                         \
)

#define SWAP(a, b) do                                                       \
{                                                                           \
	a ^= b;                                                                 \
    b ^= a;                                                                 \
    a ^= b;                                                                 \
} while(0)


#define COMPARE(x, y)                                                       \
(                                                                           \
    ((x) > (y)) - ((x) < (y))                                               \
)

#define ARRAY_SIZE(a)                                                       \
(                                                                           \
    sizeof(a) / sizeof(*a)                                                  \
)

/* ISO comparison macros */
# ifndef isgreater
#  define isgreater(x, y) (__extension__({									\
	__typeof__(x) __x = (x);												\
	__typeof__(y) __y = (y);			      								\
	!isunordered (__x, __y) && __x > __y; 									\
}))
# endif

# ifndef isgreaterequal
#  define isgreaterequal(x, y) (__extension__({								\
	__typeof__(x) __x = (x);												\
	__typeof__(y) __y = (y);			      								\
    !isunordered (__x, __y) && __x >= __y; 									\
}))
# endif

#ifndef isless
#define isless(x, y) (__extension__({ 										\
	__typeof__(x) __x = (x); 												\
	__typeof__(y) __y = (y);			      								\
    !isunordered (__x, __y) && __x < __y; 									\
}))
#endif

# ifndef islessequal
#  define islessequal(x, y) (__extension__({ 								\
	__typeof__(x) __x = (x); 												\
	__typeof__(y) __y = (y);			      								\
	!isunordered (__x, __y) && __x <= __y;									\
}))
# endif

# ifndef islessgreater
#  define islessgreater(x, y) ( __extension__({								\													\
		__typeof__(x) __x = (x); 											\
		__typeof__(y) __y = (y);							   				\
      !isunordered (__x, __y) && (__x < __y || __y < __x);					\
}))
# endif

/* Return nonzero value if arguments are unordered.  */
#ifndef isunordered
#define isunordered(u, v) (__extension__({									\
	__typeof__(u) __u = (u);												\
	__typeof__(v) __v = (v);			      								\
    fpclassify (__u) == FP_NAN || fpclassify (__v) == FP_NAN; 				\
}))
# endif


/* Non-functioning or untested */
#ifdef __CPLUSPLUS
#define PRINT(x)                                                            \
(                                                                           \
    cout<<#x<<": "<<x;                                                      \
)
#else 
#define PRINT(x)                                                            \
(                                                                           \
    printf((char *) x)                                                      \
)
#endif

#define FOR_EACH (item, in)                                                 \
(                                                                           \
    for(int keep=1,                                                         \
           count=0,                                                         \
            size=sizeof (array)/sizeof *(array);                            \
    count != size;                                                          \
    keep=1, count++)                                                        \
    for(item = (array)+count; keep; keep = !keep)                           \
)

#define IMPLIES (x,y) (!(x) || (y))

#define LENGTH(x)                                                           \
(                                                                           \
    (sizeof(a) / sizeof(*a))                                                \
)

#define SORT2(x, y, T)                                                      \
(                                                                           \
    if ((x) > (y)) SWAP((x), (y), T);                                       \
)

#define SET(d, n, v)                                                        \
(                                                                           \
    size_t i_, n_;                                                          \
    for (n_ = (n), i_ = 0; n_ > 0; --n_, ++i_)                              \
        (d)[i_] = (v);                                                      \
)

#define ZERO(d, n)                                                          \
(                                                                           \
        SET(d, n, 0)                                                            \
)

#endif /* MACROS_H_ */

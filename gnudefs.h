/* Declarations for math functions.
   Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.12 Mathematics	<math.h>
 */

#ifndef	_MATH_H
#define	_MATH_H	1

__BEGIN_DECLS

/* Get machine-dependent HUGE_VAL value (returned on overflow).
   On all IEEE754 machines, this is +Infinity.  */
#ifdef __USE_ISOC99
# include <bits/huge_valf.h>
# include <bits/huge_vall.h>

/* Get machine-dependent INFINITY value.  */
# include <bits/inf.h>

/* Get machine-dependent NAN value (returned for some domain errors).  */
# include <bits/nan.h>
#endif /* __USE_ISOC99 */

/* The file <bits/mathcalls.h> contains the prototypes for all the
   actual math functions.  These macros are used for those prototypes,
   so we can easily declare each function as both `name' and `__name',
   and can declare the float versions `namef' and `__namef'.  */

#define __MATHCALL(function,suffix, args)	\
  __MATHDECL (_Mdouble_,function,suffix, args)
#define __MATHDECL(type, function,suffix, args) \
  __MATHDECL_1(type, function,suffix, args); \
  __MATHDECL_1(type, __CONCAT(__,function),suffix, args)
#define __MATHCALLX(function,suffix, args, attrib)	\
  __MATHDECLX (_Mdouble_,function,suffix, args, attrib)
#define __MATHDECLX(type, function,suffix, args, attrib) \
  __MATHDECL_1(type, function,suffix, args) __attribute__ (attrib); \
  __MATHDECL_1(type, __CONCAT(__,function),suffix, args) __attribute__ (attrib)
#define __MATHDECL_1(type, function,suffix, args) \
  extern type __MATH_PRECNAME(function,suffix) args __THROW

#define _Mdouble_		double
#define __MATH_PRECNAME(name,r)	__CONCAT(name,r)
#define _Mdouble_BEGIN_NAMESPACE __BEGIN_NAMESPACE_STD
#define _Mdouble_END_NAMESPACE   __END_NAMESPACE_STD
#undef	_Mdouble_
#undef _Mdouble_BEGIN_NAMESPACE
#undef _Mdouble_END_NAMESPACE
#undef	__MATH_PRECNAME

#if defined __USE_MISC || defined __USE_ISOC99


/* Include the file of declarations again, this time using `float'
   instead of `double' and appending f to each function name.  */

# ifndef _Mfloat_
#  define _Mfloat_		float
# endif
# define _Mdouble_		_Mfloat_
# define __MATH_PRECNAME(name,r) name##f##r
# define _Mdouble_BEGIN_NAMESPACE __BEGIN_NAMESPACE_C99
# define _Mdouble_END_NAMESPACE   __END_NAMESPACE_C99
# include <bits/mathcalls.h>
# undef	_Mdouble_
# undef _Mdouble_BEGIN_NAMESPACE
# undef _Mdouble_END_NAMESPACE
# undef	__MATH_PRECNAME

# if !(defined __NO_LONG_DOUBLE_MATH && defined _LIBC) \
     || defined __LDBL_COMPAT
#  ifdef __LDBL_COMPAT

#   ifdef __USE_ISOC99
extern float __nldbl_nexttowardf (float __x, long double __y)
				  __THROW __attribute__ ((__const__));
#    ifdef __REDIRECT_NTH
extern float __REDIRECT_NTH (nexttowardf, (float __x, long double __y),
			     __nldbl_nexttowardf)
     __attribute__ ((__const__));
extern double __REDIRECT_NTH (nexttoward, (double __x, long double __y),
			      nextafter) __attribute__ ((__const__));
extern long double __REDIRECT_NTH (nexttowardl,
				   (long double __x, long double __y),
				   nextafter) __attribute__ ((__const__));
#    endif
#   endif

#   undef __MATHDECL_1
#   define __MATHDECL_2(type, function,suffix, args, alias) \
  extern type __REDIRECT_NTH(__MATH_PRECNAME(function,suffix), \
			     args, alias)
#   define __MATHDECL_1(type, function,suffix, args) \
  __MATHDECL_2(type, function,suffix, args, __CONCAT(function,suffix))
#  endif

/* Include the file of declarations again, this time using `long double'
   instead of `double' and appending l to each function name.  */

#  ifndef _Mlong_double_
#   define _Mlong_double_	long double
#  endif
#  define _Mdouble_		_Mlong_double_
#  define __MATH_PRECNAME(name,r) name##l##r
#  define _Mdouble_BEGIN_NAMESPACE __BEGIN_NAMESPACE_C99
#  define _Mdouble_END_NAMESPACE   __END_NAMESPACE_C99
#  define __MATH_DECLARE_LDOUBLE   1
#  include <bits/mathcalls.h>
#  undef _Mdouble_
#  undef _Mdouble_BEGIN_NAMESPACE
#  undef _Mdouble_END_NAMESPACE
#  undef __MATH_PRECNAME

# endif /* !(__NO_LONG_DOUBLE_MATH && _LIBC) || __LDBL_COMPAT */

#endif	/* Use misc or ISO C99.  */
#undef	__MATHDECL_1
#undef	__MATHDECL
#undef	__MATHCALL


#if defined __USE_MISC || defined __USE_XOPEN
/* This variable is used by `gamma' and `lgamma'.  */
extern int signgam;
#endif


/* ISO C99 defines some generic macros which work on any data type.  */
#ifdef __USE_ISOC99

/* Get the architecture specific values describing the floating-point
   evaluation.  The following symbols will get defined:

    float_t	floating-point type at least as wide as `float' used
		to evaluate `float' expressions
    double_t	floating-point type at least as wide as `double' used
		to evaluate `double' expressions

    FLT_EVAL_METHOD
		Defined to
		  0	if `float_t' is `float' and `double_t' is `double'
		  1	if `float_t' and `double_t' are `double'
		  2	if `float_t' and `double_t' are `long double'
		  else	`float_t' and `double_t' are unspecified

    INFINITY	representation of the infinity value of type `float'

    FP_FAST_FMA
    FP_FAST_FMAF
    FP_FAST_FMAL
		If defined it indicates that the `fma' function
		generally executes about as fast as a multiply and an add.
		This macro is defined only iff the `fma' function is
		implemented directly with a hardware multiply-add instructions.

    FP_ILOGB0	Expands to a value returned by `ilogb (0.0)'.
    FP_ILOGBNAN	Expands to a value returned by `ilogb (NAN)'.

    DECIMAL_DIG	Number of decimal digits supported by conversion between
		decimal and all internal floating-point formats.

*/

/* All floating-point numbers can be put in one of these categories.  */
enum
  {
    FP_NAN =
# define FP_NAN 0
      FP_NAN,
    FP_INFINITE =
# define FP_INFINITE 1
      FP_INFINITE,
    FP_ZERO =
# define FP_ZERO 2
      FP_ZERO,
    FP_SUBNORMAL =
# define FP_SUBNORMAL 3
      FP_SUBNORMAL,
    FP_NORMAL =
# define FP_NORMAL 4
      FP_NORMAL
  };

/* Return number of classification appropriate for X.  */
# ifdef __NO_LONG_DOUBLE_MATH
#  define fpclassify(x) \
     (sizeof (x) == sizeof (float) ? __fpclassifyf (x) : __fpclassify (x))
# else
#  define fpclassify(x) \
     (sizeof (x) == sizeof (float)					      \
      ? __fpclassifyf (x)						      \
      : sizeof (x) == sizeof (double)					      \
      ? __fpclassify (x) : __fpclassifyl (x))
# endif

/* Return nonzero value if sign of X is negative.  */
# ifdef __NO_LONG_DOUBLE_MATH
#  define signbit(x) \
     (sizeof (x) == sizeof (float) ? __signbitf (x) : __signbit (x))
# else
#  define signbit(x) \
     (sizeof (x) == sizeof (float)					      \
      ? __signbitf (x)							      \
      : sizeof (x) == sizeof (double)					      \
      ? __signbit (x) : __signbitl (x))
# endif

/* Return nonzero value if X is not +-Inf or NaN.  */
# ifdef __NO_LONG_DOUBLE_MATH
#  define isfinite(x) \
     (sizeof (x) == sizeof (float) ? __finitef (x) : __finite (x))
# else
#  define isfinite(x) \
     (sizeof (x) == sizeof (float)					      \
      ? __finitef (x)							      \
      : sizeof (x) == sizeof (double)					      \
      ? __finite (x) : __finitel (x))
# endif

/* Return nonzero value if X is neither zero, subnormal, Inf, nor NaN.  */
# define isnormal(x) (fpclassify (x) == FP_NORMAL)

/* Return nonzero value if X is a NaN.  We could use `fpclassify' but
   we already have this functions `__isnan' and it is faster.  */
# ifdef __NO_LONG_DOUBLE_MATH
#  define isnan(x) \
     (sizeof (x) == sizeof (float) ? __isnanf (x) : __isnan (x))
# else
#  define isnan(x) \
     (sizeof (x) == sizeof (float)					      \
      ? __isnanf (x)							      \
      : sizeof (x) == sizeof (double)					      \
      ? __isnan (x) : __isnanl (x))
# endif

/* Return nonzero value if X is positive or negative infinity.  */
# ifdef __NO_LONG_DOUBLE_MATH
#  define isinf(x) \
     (sizeof (x) == sizeof (float) ? __isinff (x) : __isinf (x))
# else
#  define isinf(x) \
     (sizeof (x) == sizeof (float)					      \
      ? __isinff (x)							      \
      : sizeof (x) == sizeof (double)					      \
      ? __isinf (x) : __isinfl (x))
# endif

/* Bitmasks for the math_errhandling macro.  */
# define MATH_ERRNO	1	/* errno set by math functions.  */
# define MATH_ERREXCEPT	2	/* Exceptions raised by math functions.  */

/* By default all functions support both errno and exception handling.
   In gcc's fast math mode and if inline functions are defined this
   might not be true.  */
# ifndef __FAST_MATH__
#  define math_errhandling	(MATH_ERRNO | MATH_ERREXCEPT)
# endif

#endif /* Use ISO C99.  */

#ifdef __USE_GNU
/* Return nonzero value if X is a signaling NaN.  */
# ifdef __NO_LONG_DOUBLE_MATH
#  define issignaling(x) \
     (sizeof (x) == sizeof (float) ? __issignalingf (x) : __issignaling (x))
# else
#  define issignaling(x) \
     (sizeof (x) == sizeof (float)					      \
      ? __issignalingf (x)						      \
      : sizeof (x) == sizeof (double)					      \
      ? __issignaling (x) : __issignalingl (x))
# endif
#endif /* Use GNU.  */

/* When compiling in strict ISO C compatible mode we must not use the
   inline functions since they, among other things, do not set the
   `errno' variable correctly.  */
#if defined __STRICT_ANSI__ && !defined __NO_MATH_INLINES
# define __NO_MATH_INLINES	1
#endif

#ifdef __USE_ISOC99
#ifdef __GNUC_PREREQ(2,97)
/* ISO C99 defines some macros to compare number while taking care for
   unordered numbers.  Many FPUs provide special instructions to support
   these operations.  Generic support in GCC for these as builtins went
   in before 3.0.0, but not all cpus added their patterns.  We define
   versions that use the builtins here, and <bits/mathinline.h> will
   undef/redefine as appropriate for the specific GCC version in use.  */
# define isgreater(x, y)        __builtin_isgreater(x, y)
# define isgreaterequal(x, y)	__builtin_isgreaterequal(x, y)
# define isless(x, y)           __builtin_isless(x, y)
# define islessequal(x, y)      __builtin_islessequal(x, y)
# define islessgreater(x, y)	__builtin_islessgreater(x, y)
# define isunordered(u, v)      __builtin_isunordered(u, v)
#endif
#endif

#ifdef __USE_ISOC99
/* If we've still got undefined comparison macros, provide defaults.  */

/* Return nonzero value if X is greater than Y.  */
# ifndef isgreater
#  define isgreater(x, y) \
  (__extension__							      \
   ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y);			      \
      !isunordered (__x, __y) && __x > __y; }))
# endif

/* Return nonzero value if X is greater than or equal to Y.  */
# ifndef isgreaterequal
#  define isgreaterequal(x, y) \
  (__extension__							      \
   ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y);			      \
      !isunordered (__x, __y) && __x >= __y; }))
# endif

/* Return nonzero value if X is less than Y.  */
# ifndef isless
#  define isless(x, y) \
  (__extension__							      \
   ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y);			      \
      !isunordered (__x, __y) && __x < __y; }))
# endif

/* Return nonzero value if X is less than or equal to Y.  */
# ifndef islessequal
#  define islessequal(x, y) \
  (__extension__							      \
   ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y);			      \
      !isunordered (__x, __y) && __x <= __y; }))
# endif

/* Return nonzero value if either X is less than Y or Y is less than X.  */
# ifndef islessgreater
#  define islessgreater(x, y) \
  (__extension__							      \
   ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y);			      \
      !isunordered (__x, __y) && (__x < __y || __y < __x); }))
# endif

/* Return nonzero value if arguments are unordered.  */
# ifndef isunordered
#  define isunordered(u, v) \
  (__extension__							      \
   ({ __typeof__(u) __u = (u); __typeof__(v) __v = (v);			      \
      fpclassify (__u) == FP_NAN || fpclassify (__v) == FP_NAN; }))
# endif

#endif

__END_DECLS


#endif /* math.h  */

#include <stdio.h>

/* Domain/range error */
static void drerror(char *msg) {
    fprintf(stderr, msg);
    exit(1);
}
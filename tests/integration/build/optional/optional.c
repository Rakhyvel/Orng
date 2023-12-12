/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _828_main(void);

/* Function definitions */
int64_t _828_main(void) {
    int64_t _828_t0;
    struct0 _829_x;
    int64_t _828_t4;
    int64_t _828_$retval;
    _828_t0 = 4;
    _829_x = (struct0) {.tag=1, ._1=_828_t0};
    _829_x = (struct0) {.tag=0};
    _828_t4 = 113;
    _829_x = (struct0) {.tag=1, ._1=_828_t4};
    _828_$retval = _829_x._1;
    return _828_$retval;
}

int main(void) {
  printf("%ld",_828_main());
  return 0;
}

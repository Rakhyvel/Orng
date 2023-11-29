/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t* _1;
    int64_t* _2;
    int64_t* _3;
} struct0;

/* Function forward definitions */
int64_t _25_main(void);

/* Function definitions */
int64_t _25_main(void) {
    int64_t _26_a;
    int64_t _26_b;
    int64_t _26_c;
    int64_t _26_d;
    int64_t* _25_t5;
    int64_t* _25_t6;
    int64_t* _25_t7;
    int64_t* _25_t8;
    struct0 _26_x;
    int64_t _25_t10;
    int64_t _25_t11;
    int64_t _25_$retval;
    _26_a = 1;
    _26_b = 2;
    _26_c = 3;
    _26_d = 4;
    _25_t5 = &_26_a;
    _25_t6 = &_26_b;
    _25_t7 = &_26_c;
    _25_t8 = &_26_d;
    _26_x = (struct0) {_25_t5, _25_t6, _25_t7, _25_t8};
    _25_t10 = 2;
    **((int64_t**)&_26_x + _25_t10) = 71;
    _25_t11 = 2;
    _25_$retval = **((int64_t**)&_26_x + _25_t11);
    return _25_$retval;
}

int main(void) {
  printf("%ld",_25_main());
  return 0;
}

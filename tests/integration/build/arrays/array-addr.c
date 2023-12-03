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
int64_t _16_main(void);

/* Function definitions */
int64_t _16_main(void) {
    int64_t _17_a;
    int64_t _17_b;
    int64_t _17_c;
    int64_t _17_d;
    int64_t* _16_t5;
    int64_t* _16_t6;
    int64_t* _16_t7;
    int64_t* _16_t8;
    struct0 _17_x;
    int64_t _16_t10;
    int64_t _16_t11;
    int64_t _16_$retval;
    _17_a = 1;
    _17_b = 2;
    _17_c = 3;
    _17_d = 4;
    _16_t5 = &_17_a;
    _16_t6 = &_17_b;
    _16_t7 = &_17_c;
    _16_t8 = &_17_d;
    _17_x = (struct0) {_16_t5, _16_t6, _16_t7, _16_t8};
    _16_t10 = 2;
    **((int64_t**)&_17_x + _16_t10) = 71;
    _16_t11 = 2;
    _16_$retval = **((int64_t**)&_17_x + _16_t11);
    return _16_$retval;
}

int main(void) {
  printf("%ld",_16_main());
  return 0;
}

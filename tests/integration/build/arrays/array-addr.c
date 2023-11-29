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
int64_t _20_main(void);

/* Function definitions */
int64_t _20_main(void) {
    int64_t _21_a;
    int64_t _21_b;
    int64_t _21_c;
    int64_t _21_d;
    int64_t* _20_t5;
    int64_t* _20_t6;
    int64_t* _20_t7;
    int64_t* _20_t8;
    struct0 _21_x;
    int64_t _20_t10;
    int64_t _20_t11;
    int64_t _20_$retval;
    _21_a = 1;
    _21_b = 2;
    _21_c = 3;
    _21_d = 4;
    _20_t5 = &_21_a;
    _20_t6 = &_21_b;
    _20_t7 = &_21_c;
    _20_t8 = &_21_d;
    _21_x = (struct0) {_20_t5, _20_t6, _20_t7, _20_t8};
    _20_t10 = 2;
    **((int64_t**)&_21_x + _20_t10) = 71;
    _20_t11 = 2;
    _20_$retval = **((int64_t**)&_21_x + _20_t11);
    return _20_$retval;
}

int main(void) {
  printf("%ld",_20_main());
  return 0;
}

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
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    int64_t _2_a;
    int64_t _2_b;
    int64_t _2_c;
    int64_t _2_d;
    int64_t* _1_t5;
    int64_t* _1_t6;
    int64_t* _1_t7;
    int64_t* _1_t8;
    struct0 _2_x;
    int64_t* _1_t14;
    int64_t _1_$retval;
    _2_a = 1;
    _2_b = 2;
    _2_c = 3;
    _2_d = 4;
    _1_t5 = &_2_a;
    _1_t6 = &_2_b;
    _1_t7 = &_2_c;
    _1_t8 = &_2_d;
    _2_x = (struct0) {_1_t5, _1_t6, _1_t7, _1_t8};
    **((int64_t**)&_2_x + 2) = 71;
    _1_t14 = *((int64_t**)&_2_x + 2);
    _1_$retval = *_1_t14;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}

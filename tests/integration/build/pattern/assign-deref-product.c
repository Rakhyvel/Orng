/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    struct0 _3_x;
    int64_t _2_t4;
    int64_t* _3_a;
    int64_t _2_t11;
    int64_t* _3_b;
    int64_t _2_t18;
    int64_t* _3_c;
    int64_t _2_t26;
    int64_t _2_t27;
    int64_t _2_t28;
    struct0 _2_t25;
    int64_t _2_t30;
    int64_t _2_t32;
    int64_t _2_t34;
    int64_t _2_t35;
    int64_t _2_t36;
    int64_t _2_t37;
    int64_t _2_t38;
    int64_t _2_$retval;
BB0:
    _2_t1 = 0;
    _2_t2 = 0;
    _2_t3 = 0;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3};
    _2_t4 = 0;
    _3_a = (((int64_t*)(&_3_x))+_2_t4);
    _2_t11 = 1;
    _3_b = (((int64_t*)(&_3_x))+_2_t11);
    _2_t18 = 2;
    _3_c = (((int64_t*)(&_3_x))+_2_t18);
    _2_t26 = 100;
    _2_t27 = 30;
    _2_t28 = 30;
    _2_t25 = (struct0) {_2_t26, _2_t27, _2_t28};
    _2_t30 = (&_2_t25)->_0;
    **&_3_a = _2_t30;
    _2_t32 = (&_2_t25)->_1;
    **&_3_b = _2_t32;
    _2_t34 = (&_2_t25)->_2;
    **&_3_c = _2_t34;
    _2_t35 = *_3_a;
    _2_t36 = *_3_b;
    _2_t37 = _2_t35 + _2_t36;
    _2_t38 = *_3_c;
    _2_$retval = _2_t37 + _2_t38;
    return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}


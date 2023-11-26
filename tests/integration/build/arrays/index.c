/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct2;

typedef struct2(*function0)(    int64_t,     int64_t);

/* Function forward definitions */
int64_t _74_main(void);
struct2 _76_get_array(int64_t _76_a,int64_t _76_b);

/* Function definitions */
int64_t _74_main(void) {
    function0 _74_t0;
    int64_t _74_t2;
    int64_t _74_t3;
    struct2 _74_t1;
    struct2 _75_x;
    int64_t _74_t4;
    int64_t _74_t5;
    int64_t _74_t6;
    int64_t _74_t7;
    int64_t _74_t8;
    int64_t _74_t9;
    int64_t _74_$retval;
    _74_t0 = _76_get_array;
    _74_t2 = 15;
    _74_t3 = 16;
    $lines[$line_idx++] = "tests/integration/arrays/index.orng:3:32:\n    let x: [4]Int  = get_array(15, 16)\n                              ^";
    _74_t1 = _74_t0(_74_t2, _74_t3);
    $line_idx--;
    _75_x = _74_t1;
    _74_t4 = 0;
    _74_t5 = 1;
    _74_t6 = $add_int64_t(*((int64_t*)&_75_x + _74_t4), *((int64_t*)&_75_x + _74_t5), "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _74_t7 = 2;
    _74_t8 = $add_int64_t(_74_t6, *((int64_t*)&_75_x + _74_t7), "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _74_t9 = 3;
    _74_$retval = $add_int64_t(_74_t8, *((int64_t*)&_75_x + _74_t9), "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _74_$retval;
}

struct2 _76_get_array(int64_t _76_a,int64_t _76_b) {
    struct2 _76_$retval;
    _76_$retval = (struct2) {_76_a, _76_b, _76_a, _76_b};
    return _76_$retval;
}

int main(void) {
  printf("%ld",_74_main());
  return 0;
}

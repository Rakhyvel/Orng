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

typedef struct2(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _130_main(void);
struct2 _134_get_array(int64_t _134_a,int64_t _134_b);

/* Function definitions */
int64_t _130_main(void) {
    function0 _130_t0;
    int64_t _130_t2;
    int64_t _130_t3;
    struct2 _130_t1;
    struct2 _131_x;
    int64_t _130_t4;
    int64_t _130_t5;
    int64_t _130_t6;
    int64_t _130_t7;
    int64_t _130_t8;
    int64_t _130_t9;
    int64_t _130_$retval;
    _130_t0 = _134_get_array;
    _130_t2 = 15;
    _130_t3 = 16;
    $lines[$line_idx++] = "tests/integration/arrays/index.orng:3:32:\n    let x: [4]Int  = get_array(15, 16)\n                              ^";
    _130_t1 = _130_t0(_130_t2, _130_t3);
    $line_idx--;
    _131_x = _130_t1;
    _130_t4 = 0;
    _130_t5 = 1;
    _130_t6 = $add_int64_t(*((int64_t*)&_131_x + _130_t4), *((int64_t*)&_131_x + _130_t5), "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _130_t7 = 2;
    _130_t8 = $add_int64_t(_130_t6, *((int64_t*)&_131_x + _130_t7), "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _130_t9 = 3;
    _130_$retval = $add_int64_t(_130_t8, *((int64_t*)&_131_x + _130_t9), "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _130_$retval;
}

struct2 _134_get_array(int64_t _134_a,int64_t _134_b) {
    struct2 _134_$retval;
    _134_$retval = (struct2) {_134_a, _134_b, _134_a, _134_b};
    return _134_$retval;
}

int main(void) {
  printf("%ld",_130_main());
  return 0;
}

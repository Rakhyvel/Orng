/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

typedef struct {
    function0 _0;
    int64_t _1;
} struct2;

typedef int64_t(*function1)(    function0,     int64_t);

/* Function forward definitions */
int64_t _2_main(void);
int64_t _4_$anon0(int64_t _4_x);
int64_t _6_apply(function0 _6_f,int64_t _6_x);

/* Function definitions */
int64_t _2_main(void) {
    function0 _3_id;
    function1 _2_t1;
    int64_t _2_t3;
    int64_t _2_t2;
    int64_t _2_$retval;
    _3_id = _4_$anon0;
    _2_t1 = _6_apply;
    _2_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _2_t2 = _2_t1(_3_id, _2_t3);
    $line_idx--;
    _2_$retval = _2_t2;
    return _2_$retval;
}

int64_t _4_$anon0(int64_t _4_x) {
    int64_t _4_$retval;
    _4_$retval = _4_x;
    return _4_$retval;
}

int64_t _6_apply(function0 _6_f,int64_t _6_x) {
    int64_t _6_t0;
    int64_t _6_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _6_t0 = _6_f(_6_x);
    $line_idx--;
    _6_$retval = _6_t0;
    return _6_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}

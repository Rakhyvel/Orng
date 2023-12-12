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

typedef int64_t(*function1)(function0, int64_t);

/* Function forward definitions */
int64_t _681_main(void);
int64_t _683_$anon155(int64_t _683_x);
int64_t _685_apply(function0 _685_f,int64_t _685_x);

/* Function definitions */
int64_t _681_main(void) {
    function0 _682_id;
    function1 _681_t1;
    int64_t _681_t3;
    int64_t _681_t2;
    int64_t _681_$retval;
    _682_id = _683_$anon155;
    _681_t1 = _685_apply;
    _681_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _681_t2 = _681_t1(_682_id, _681_t3);
    $line_idx--;
    _681_$retval = _681_t2;
    return _681_$retval;
}

int64_t _683_$anon155(int64_t _683_x) {
    int64_t _683_$retval;
    _683_$retval = _683_x;
    return _683_$retval;
}

int64_t _685_apply(function0 _685_f,int64_t _685_x) {
    int64_t _685_t0;
    int64_t _685_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _685_t0 = _685_f(_685_x);
    $line_idx--;
    _685_$retval = _685_t0;
    return _685_$retval;
}

int main(void) {
  printf("%ld",_681_main());
  return 0;
}

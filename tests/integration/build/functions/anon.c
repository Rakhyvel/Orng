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
int64_t _838_main(void);
int64_t _840_$anon198(int64_t _840_x);
int64_t _843_apply(function0 _843_f,int64_t _843_x);

/* Function definitions */
int64_t _838_main(void) {
    function0 _839_id;
    function1 _838_t1;
    int64_t _838_t3;
    int64_t _838_t2;
    int64_t _838_$retval;
    _839_id = _840_$anon198;
    _838_t1 = _843_apply;
    _838_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _838_t2 = _838_t1(_839_id, _838_t3);
    $line_idx--;
    _838_$retval = _838_t2;
    return _838_$retval;
}

int64_t _840_$anon198(int64_t _840_x) {
    int64_t _840_$retval;
    _840_$retval = _840_x;
    return _840_$retval;
}

int64_t _843_apply(function0 _843_f,int64_t _843_x) {
    int64_t _843_t0;
    int64_t _843_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _843_t0 = _843_f(_843_x);
    $line_idx--;
    _843_$retval = _843_t0;
    return _843_$retval;
}

int main(void) {
  printf("%ld",_838_main());
  return 0;
}

/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct2;

/* Typedefs */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    function0 _0;
    int64_t _1;
};

typedef int64_t(*function1)(function0, int64_t);

/* Function forward definitions */
int64_t _927_main(void);
int64_t _929_$anon93(int64_t _929_x);
int64_t _931_apply(function0 _931_f, int64_t _931_x);

/* Function definitions */
int64_t _927_main(void){
    function0 _928_id;
    function1 _927_t1;
    int64_t _927_t3;
    int64_t _927_t2;
    int64_t _927_$retval;
    _928_id = _929_$anon93;
    _927_t1 = _931_apply;
    _927_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _927_t2 = _927_t1(_928_id, _927_t3);
    $line_idx--;
    _927_$retval = _927_t2;
    return _927_$retval;
}

int64_t _929_$anon93(int64_t _929_x){
    int64_t _929_$retval;
    _929_$retval = _929_x;
    return _929_$retval;
}

int64_t _931_apply(function0 _931_f, int64_t _931_x){
    int64_t _931_t0;
    int64_t _931_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _931_t0 = _931_f(_931_x);
    $line_idx--;
    _931_$retval = _931_t0;
    return _931_$retval;
}

int main(void) {
  printf("%ld",_927_main());
  return 0;
}

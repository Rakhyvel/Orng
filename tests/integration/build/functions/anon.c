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
int64_t _915_main(void);
int64_t _917_$anon93(int64_t _917_x);
int64_t _919_apply(function0 _919_f, int64_t _919_x);

/* Function definitions */
int64_t _915_main(void){
    function0 _916_id;
    function1 _915_t1;
    int64_t _915_t3;
    int64_t _915_t2;
    int64_t _915_$retval;
    _916_id = _917_$anon93;
    _915_t1 = _919_apply;
    _915_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _915_t2 = _915_t1(_916_id, _915_t3);
    $line_idx--;
    _915_$retval = _915_t2;
    return _915_$retval;
}

int64_t _917_$anon93(int64_t _917_x){
    int64_t _917_$retval;
    _917_$retval = _917_x;
    return _917_$retval;
}

int64_t _919_apply(function0 _919_f, int64_t _919_x){
    int64_t _919_t0;
    int64_t _919_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _919_t0 = _919_f(_919_x);
    $line_idx--;
    _919_$retval = _919_t0;
    return _919_$retval;
}

int main(void) {
  printf("%ld",_915_main());
  return 0;
}

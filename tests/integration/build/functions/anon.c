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
int64_t _876_main(void);
int64_t _878_$anon163(int64_t _878_x);
int64_t _880_apply(function0 _880_f,int64_t _880_x);

/* Function definitions */
int64_t _876_main(void){
    function0 _877_id;
    function1 _876_t1;
    int64_t _876_t3;
    int64_t _876_t2;
    int64_t _876_$retval;
    _877_id = _878_$anon163;
    _876_t1 = _880_apply;
    _876_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _876_t2 = _876_t1(_877_id, _876_t3);
    $line_idx--;
    _876_$retval = _876_t2;
    return _876_$retval;
}

int64_t _878_$anon163(int64_t _878_x){
    int64_t _878_$retval;
    _878_$retval = _878_x;
    return _878_$retval;
}

int64_t _880_apply(function0 _880_f,int64_t _880_x){
    int64_t _880_t0;
    int64_t _880_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _880_t0 = _880_f(_880_x);
    $line_idx--;
    _880_$retval = _880_t0;
    return _880_$retval;
}

int main(void) {
  printf("%ld",_876_main());
  return 0;
}

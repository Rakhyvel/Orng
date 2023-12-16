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
int64_t _887_main(void);
int64_t _889_$anon166(int64_t _889_x);
int64_t _891_apply(function0 _891_f,int64_t _891_x);

/* Function definitions */
int64_t _887_main(void){
    function0 _888_id;
    function1 _887_t1;
    int64_t _887_t3;
    int64_t _887_t2;
    int64_t _887_$retval;
    _888_id = _889_$anon166;
    _887_t1 = _891_apply;
    _887_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _887_t2 = _887_t1(_888_id, _887_t3);
    $line_idx--;
    _887_$retval = _887_t2;
    return _887_$retval;
}

int64_t _889_$anon166(int64_t _889_x){
    int64_t _889_$retval;
    _889_$retval = _889_x;
    return _889_$retval;
}

int64_t _891_apply(function0 _891_f,int64_t _891_x){
    int64_t _891_t0;
    int64_t _891_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _891_t0 = _891_f(_891_x);
    $line_idx--;
    _891_$retval = _891_t0;
    return _891_$retval;
}

int main(void) {
  printf("%ld",_887_main());
  return 0;
}

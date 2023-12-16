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
int64_t _947_main(void);
int64_t _949_$anon176(int64_t _949_x);
int64_t _951_apply(function0 _951_f,int64_t _951_x);

/* Function definitions */
int64_t _947_main(void){
    function0 _948_id;
    function1 _947_t1;
    int64_t _947_t3;
    int64_t _947_t2;
    int64_t _947_$retval;
    _948_id = _949_$anon176;
    _947_t1 = _951_apply;
    _947_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _947_t2 = _947_t1(_948_id, _947_t3);
    $line_idx--;
    _947_$retval = _947_t2;
    return _947_$retval;
}

int64_t _949_$anon176(int64_t _949_x){
    int64_t _949_$retval;
    _949_$retval = _949_x;
    return _949_$retval;
}

int64_t _951_apply(function0 _951_f,int64_t _951_x){
    int64_t _951_t0;
    int64_t _951_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _951_t0 = _951_f(_951_x);
    $line_idx--;
    _951_$retval = _951_t0;
    return _951_$retval;
}

int main(void) {
  printf("%ld",_947_main());
  return 0;
}

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
int64_t _1039_main(void);
int64_t _1041_$anon217(int64_t _1041_x);
int64_t _1043_apply(function0 _1043_f,int64_t _1043_x);

/* Function definitions */
int64_t _1039_main(void){
    function0 _1040_id;
    function1 _1039_t1;
    int64_t _1039_t3;
    int64_t _1039_t2;
    int64_t _1039_$retval;
    _1040_id = _1041_$anon217;
    _1039_t1 = _1043_apply;
    _1039_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _1039_t2 = _1039_t1(_1040_id, _1039_t3);
    $line_idx--;
    _1039_$retval = _1039_t2;
    return _1039_$retval;
}

int64_t _1041_$anon217(int64_t _1041_x){
    int64_t _1041_$retval;
    _1041_$retval = _1041_x;
    return _1041_$retval;
}

int64_t _1043_apply(function0 _1043_f,int64_t _1043_x){
    int64_t _1043_t0;
    int64_t _1043_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _1043_t0 = _1043_f(_1043_x);
    $line_idx--;
    _1043_$retval = _1043_t0;
    return _1043_$retval;
}

int main(void) {
  printf("%ld",_1039_main());
  return 0;
}

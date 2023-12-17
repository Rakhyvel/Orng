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
int64_t _1032_main(void);
int64_t _1034_$anon217(int64_t _1034_x);
int64_t _1036_apply(function0 _1036_f,int64_t _1036_x);

/* Function definitions */
int64_t _1032_main(void){
    function0 _1033_id;
    function1 _1032_t1;
    int64_t _1032_t3;
    int64_t _1032_t2;
    int64_t _1032_$retval;
    _1033_id = _1034_$anon217;
    _1032_t1 = _1036_apply;
    _1032_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _1032_t2 = _1032_t1(_1033_id, _1032_t3);
    $line_idx--;
    _1032_$retval = _1032_t2;
    return _1032_$retval;
}

int64_t _1034_$anon217(int64_t _1034_x){
    int64_t _1034_$retval;
    _1034_$retval = _1034_x;
    return _1034_$retval;
}

int64_t _1036_apply(function0 _1036_f,int64_t _1036_x){
    int64_t _1036_t0;
    int64_t _1036_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _1036_t0 = _1036_f(_1036_x);
    $line_idx--;
    _1036_$retval = _1036_t0;
    return _1036_$retval;
}

int main(void) {
  printf("%ld",_1032_main());
  return 0;
}

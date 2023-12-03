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
int64_t _649_main(void);
int64_t _651_$anon137(int64_t _651_x);
int64_t _653_apply(function0 _653_f,int64_t _653_x);

/* Function definitions */
int64_t _649_main(void) {
    function0 _650_id;
    function1 _649_t1;
    int64_t _649_t3;
    int64_t _649_t2;
    int64_t _649_$retval;
    _650_id = _651_$anon137;
    _649_t1 = _653_apply;
    _649_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _649_t2 = _649_t1(_650_id, _649_t3);
    $line_idx--;
    _649_$retval = _649_t2;
    return _649_$retval;
}

int64_t _651_$anon137(int64_t _651_x) {
    int64_t _651_$retval;
    _651_$retval = _651_x;
    return _651_$retval;
}

int64_t _653_apply(function0 _653_f,int64_t _653_x) {
    int64_t _653_t0;
    int64_t _653_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _653_t0 = _653_f(_653_x);
    $line_idx--;
    _653_$retval = _653_t0;
    return _653_$retval;
}

int main(void) {
  printf("%ld",_649_main());
  return 0;
}

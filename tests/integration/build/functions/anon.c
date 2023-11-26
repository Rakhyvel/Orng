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
int64_t _586_main(void);
int64_t _588_$anon3(int64_t _588_x);
int64_t _590_apply(function0 _590_f,int64_t _590_x);

/* Function definitions */
int64_t _586_main(void) {
    function0 _587_id;
    function1 _586_t1;
    int64_t _586_t3;
    int64_t _586_t2;
    int64_t _586_$retval;
    _587_id = _588_$anon3;
    _586_t1 = _590_apply;
    _586_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _586_t2 = _586_t1(_587_id, _586_t3);
    $line_idx--;
    _586_$retval = _586_t2;
    return _586_$retval;
}

int64_t _588_$anon3(int64_t _588_x) {
    int64_t _588_$retval;
    _588_$retval = _588_x;
    return _588_$retval;
}

int64_t _590_apply(function0 _590_f,int64_t _590_x) {
    int64_t _590_t0;
    int64_t _590_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _590_t0 = _590_f(_590_x);
    $line_idx--;
    _590_$retval = _590_t0;
    return _590_$retval;
}

int main(void) {
  printf("%ld",_586_main());
  return 0;
}

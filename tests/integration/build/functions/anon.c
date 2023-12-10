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
int64_t _673_main(void);
int64_t _675_$anon154(int64_t _675_x);
int64_t _677_apply(function0 _677_f,int64_t _677_x);

/* Function definitions */
int64_t _673_main(void) {
    function0 _674_id;
    function1 _673_t1;
    int64_t _673_t3;
    int64_t _673_t2;
    int64_t _673_$retval;
    _674_id = _675_$anon154;
    _673_t1 = _677_apply;
    _673_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _673_t2 = _673_t1(_674_id, _673_t3);
    $line_idx--;
    _673_$retval = _673_t2;
    return _673_$retval;
}

int64_t _675_$anon154(int64_t _675_x) {
    int64_t _675_$retval;
    _675_$retval = _675_x;
    return _675_$retval;
}

int64_t _677_apply(function0 _677_f,int64_t _677_x) {
    int64_t _677_t0;
    int64_t _677_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _677_t0 = _677_f(_677_x);
    $line_idx--;
    _677_$retval = _677_t0;
    return _677_$retval;
}

int main(void) {
  printf("%ld",_673_main());
  return 0;
}

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
int64_t _840_main(void);
int64_t _842_$anon200(int64_t _842_x);
int64_t _845_apply(function0 _845_f,int64_t _845_x);

/* Function definitions */
int64_t _840_main(void) {
    function0 _841_id;
    function1 _840_t1;
    int64_t _840_t3;
    int64_t _840_t2;
    int64_t _840_$retval;
    _841_id = _842_$anon200;
    _840_t1 = _845_apply;
    _840_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _840_t2 = _840_t1(_841_id, _840_t3);
    $line_idx--;
    _840_$retval = _840_t2;
    return _840_$retval;
}

int64_t _842_$anon200(int64_t _842_x) {
    int64_t _842_$retval;
    _842_$retval = _842_x;
    return _842_$retval;
}

int64_t _845_apply(function0 _845_f,int64_t _845_x) {
    int64_t _845_t0;
    int64_t _845_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _845_t0 = _845_f(_845_x);
    $line_idx--;
    _845_$retval = _845_t0;
    return _845_$retval;
}

int main(void) {
  printf("%ld",_840_main());
  return 0;
}

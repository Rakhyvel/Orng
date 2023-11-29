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
int64_t _689_main(void);
int64_t _691_$anon53(int64_t _691_x);
int64_t _693_apply(function0 _693_f,int64_t _693_x);

/* Function definitions */
int64_t _689_main(void) {
    function0 _690_id;
    function1 _689_t1;
    int64_t _689_t3;
    int64_t _689_t2;
    int64_t _689_$retval;
    _690_id = _691_$anon53;
    _689_t1 = _693_apply;
    _689_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _689_t2 = _689_t1(_690_id, _689_t3);
    $line_idx--;
    _689_$retval = _689_t2;
    return _689_$retval;
}

int64_t _691_$anon53(int64_t _691_x) {
    int64_t _691_$retval;
    _691_$retval = _691_x;
    return _691_$retval;
}

int64_t _693_apply(function0 _693_f,int64_t _693_x) {
    int64_t _693_t0;
    int64_t _693_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _693_t0 = _693_f(_693_x);
    $line_idx--;
    _693_$retval = _693_t0;
    return _693_$retval;
}

int main(void) {
  printf("%ld",_689_main());
  return 0;
}

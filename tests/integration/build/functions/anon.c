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
int64_t _617_main(void);
int64_t _619_$anon8(int64_t _619_x);
int64_t _621_apply(function0 _621_f,int64_t _621_x);

/* Function definitions */
int64_t _617_main(void) {
    function0 _618_id;
    function1 _617_t1;
    int64_t _617_t3;
    int64_t _617_t2;
    int64_t _617_$retval;
    _618_id = _619_$anon8;
    _617_t1 = _621_apply;
    _617_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _617_t2 = _617_t1(_618_id, _617_t3);
    $line_idx--;
    _617_$retval = _617_t2;
    return _617_$retval;
}

int64_t _619_$anon8(int64_t _619_x) {
    int64_t _619_$retval;
    _619_$retval = _619_x;
    return _619_$retval;
}

int64_t _621_apply(function0 _621_f,int64_t _621_x) {
    int64_t _621_t0;
    int64_t _621_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _621_t0 = _621_f(_621_x);
    $line_idx--;
    _621_$retval = _621_t0;
    return _621_$retval;
}

int main(void) {
  printf("%ld",_617_main());
  return 0;
}

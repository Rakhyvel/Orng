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
int64_t _700_main(void);
int64_t _702_$anon157(int64_t _702_x);
int64_t _704_apply(function0 _704_f,int64_t _704_x);

/* Function definitions */
int64_t _700_main(void) {
    function0 _701_id;
    function1 _700_t1;
    int64_t _700_t3;
    int64_t _700_t2;
    int64_t _700_$retval;
    _701_id = _702_$anon157;
    _700_t1 = _704_apply;
    _700_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _700_t2 = _700_t1(_701_id, _700_t3);
    $line_idx--;
    _700_$retval = _700_t2;
    return _700_$retval;
}

int64_t _702_$anon157(int64_t _702_x) {
    int64_t _702_$retval;
    _702_$retval = _702_x;
    return _702_$retval;
}

int64_t _704_apply(function0 _704_f,int64_t _704_x) {
    int64_t _704_t0;
    int64_t _704_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _704_t0 = _704_f(_704_x);
    $line_idx--;
    _704_$retval = _704_t0;
    return _704_$retval;
}

int main(void) {
  printf("%ld",_700_main());
  return 0;
}

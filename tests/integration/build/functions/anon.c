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
int64_t _817_main(void);
int64_t _819_$anon187(int64_t _819_x);
int64_t _822_apply(function0 _822_f,int64_t _822_x);

/* Function definitions */
int64_t _817_main(void) {
    function0 _818_id;
    function1 _817_t1;
    int64_t _817_t3;
    int64_t _817_t2;
    int64_t _817_$retval;
    _818_id = _819_$anon187;
    _817_t1 = _822_apply;
    _817_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _817_t2 = _817_t1(_818_id, _817_t3);
    $line_idx--;
    _817_$retval = _817_t2;
    return _817_$retval;
}

int64_t _819_$anon187(int64_t _819_x) {
    int64_t _819_$retval;
    _819_$retval = _819_x;
    return _819_$retval;
}

int64_t _822_apply(function0 _822_f,int64_t _822_x) {
    int64_t _822_t0;
    int64_t _822_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _822_t0 = _822_f(_822_x);
    $line_idx--;
    _822_$retval = _822_t0;
    return _822_$retval;
}

int main(void) {
  printf("%ld",_817_main());
  return 0;
}

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
int64_t _868_main(void);
int64_t _870_$anon160(int64_t _870_x);
int64_t _872_apply(function0 _872_f,int64_t _872_x);

/* Function definitions */
int64_t _868_main(void) {
    function0 _869_id;
    function1 _868_t1;
    int64_t _868_t3;
    int64_t _868_t2;
    int64_t _868_$retval;
    _869_id = _870_$anon160;
    _868_t1 = _872_apply;
    _868_t3 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _868_t2 = _868_t1(_869_id, _868_t3);
    $line_idx--;
    _868_$retval = _868_t2;
    return _868_$retval;
}

int64_t _870_$anon160(int64_t _870_x) {
    int64_t _870_$retval;
    _870_$retval = _870_x;
    return _870_$retval;
}

int64_t _872_apply(function0 _872_f,int64_t _872_x) {
    int64_t _872_t0;
    int64_t _872_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _872_t0 = _872_f(_872_x);
    $line_idx--;
    _872_$retval = _872_t0;
    return _872_$retval;
}

int main(void) {
  printf("%ld",_868_main());
  return 0;
}

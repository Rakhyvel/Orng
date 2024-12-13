/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct2;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    function0 _0;
    int64_t _1;
};

typedef int64_t(*function1)(function0, int64_t);

/* Function forward definitions */
int64_t _959_main(void);
int64_t _961_$anon98(int64_t _961_x);
int64_t _963_apply(function0 _963_f, int64_t _963_x);


/* Function definitions */
int64_t _959_main(void){
    function0 _960_id;
    function1 _959_t2;
    int64_t _959_t4;
    int64_t _959_t3;
    int64_t _959_$retval;
    _960_id = (function0) _961_$anon98;
    _959_t2 = (function1) _963_apply;
    _959_t4 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _959_t3 = _959_t2(_960_id, _959_t4);
    $line_idx--;
    _959_$retval = _959_t3;
    return _959_$retval;
}

int64_t _961_$anon98(int64_t _961_x){
    int64_t _961_$retval;
    goto BB1141;
BB1141:
    _961_$retval = _961_x;
    return _961_$retval;
}

int64_t _963_apply(function0 _963_f, int64_t _963_x){
    int64_t _963_t0;
    int64_t _963_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _963_t0 = _963_f(_963_x);
    $line_idx--;
    _963_$retval = _963_t0;
    return _963_$retval;
}


int main(void) {
  printf("%ld",_959_main());
  return 0;
}

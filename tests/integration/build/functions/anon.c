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
int64_t _931_main(void);
int64_t _933_$anon93(int64_t _933_x);
int64_t _935_apply(function0 _935_f, int64_t _935_x);


/* Function definitions */
int64_t _931_main(void){
    function0 _932_id;
    function1 _931_t2;
    int64_t _931_t4;
    int64_t _931_t3;
    int64_t _931_$retval;
    _932_id = (function0) _933_$anon93;
    _931_t2 = (function1) _935_apply;
    _931_t4 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _931_t3 = _931_t2(_932_id, _931_t4);
    $line_idx--;
    _931_$retval = _931_t3;
    return _931_$retval;
}

int64_t _933_$anon93(int64_t _933_x){
    int64_t _933_$retval;
    goto BB1107;
BB1107:
    _933_$retval = _933_x;
    return _933_$retval;
}

int64_t _935_apply(function0 _935_f, int64_t _935_x){
    int64_t _935_t0;
    int64_t _935_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _935_t0 = _935_f(_935_x);
    $line_idx--;
    _935_$retval = _935_t0;
    return _935_$retval;
}


int main(void) {
  printf("%ld",_931_main());
  return 0;
}

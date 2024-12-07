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
int64_t _937_main(void);
int64_t _939_$anon93(int64_t _939_x);
int64_t _941_apply(function0 _941_f, int64_t _941_x);


/* Function definitions */
int64_t _937_main(void){
    function0 _938_id;
    function1 _937_t2;
    int64_t _937_t4;
    int64_t _937_t3;
    int64_t _937_$retval;
    _938_id = (function0) _939_$anon93;
    _937_t2 = (function1) _941_apply;
    _937_t4 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _937_t3 = _937_t2(_938_id, _937_t4);
    $line_idx--;
    _937_$retval = _937_t3;
    return _937_$retval;
}

int64_t _939_$anon93(int64_t _939_x){
    int64_t _939_$retval;
    goto BB1120;
BB1120:
    _939_$retval = _939_x;
    return _939_$retval;
}

int64_t _941_apply(function0 _941_f, int64_t _941_x){
    int64_t _941_t0;
    int64_t _941_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _941_t0 = _941_f(_941_x);
    $line_idx--;
    _941_$retval = _941_t0;
    return _941_$retval;
}


int main(void) {
  printf("%ld",_937_main());
  return 0;
}

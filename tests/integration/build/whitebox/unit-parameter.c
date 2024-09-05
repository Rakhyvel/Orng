/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _1;
};

typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _94_main(void);
int64_t _96_f(int64_t _96_x);


/* Function definitions */
int64_t _94_main(void){
    function0 _94_t0;
    int64_t _94_t3;
    int64_t _94_t1;
    int64_t _94_$retval;
    _94_t0 = (function0) _96_f;
    _94_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _94_t1 = _94_t0(_94_t3);
    $line_idx--;
    _94_$retval = _94_t1;
    return _94_$retval;
}

int64_t _96_f(int64_t _96_x){
    int64_t _96_$retval;
    _96_$retval = _96_x;
    return _96_$retval;
}


int main(void) {
  printf("%ld",_94_main());
  return 0;
}

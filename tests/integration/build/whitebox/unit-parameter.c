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
int64_t _1946_main(void);
int64_t _1948_f(int64_t _1948_x);


/* Function definitions */
int64_t _1946_main(void){
    function0 _1946_t0;
    int64_t _1946_t3;
    int64_t _1946_t1;
    int64_t _1946_$retval;
    _1946_t0 = (function0) _1948_f;
    _1946_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1946_t1 = _1946_t0(_1946_t3);
    $line_idx--;
    _1946_$retval = _1946_t1;
    return _1946_$retval;
}

int64_t _1948_f(int64_t _1948_x){
    int64_t _1948_$retval;
    _1948_$retval = _1948_x;
    return _1948_$retval;
}


int main(void) {
  printf("%ld",_1946_main());
  return 0;
}

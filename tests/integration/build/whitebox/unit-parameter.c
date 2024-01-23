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
int64_t _1724_main(void);
int64_t _1726_f(int64_t _1726_x);


/* Function definitions */
int64_t _1724_main(void){
    function0 _1724_t0;
    int64_t _1724_t3;
    int64_t _1724_t1;
    int64_t _1724_$retval;
    _1724_t0 = _1726_f;
    _1724_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1724_t1 = _1724_t0(_1724_t3);
    $line_idx--;
    _1724_$retval = _1724_t1;
    return _1724_$retval;
}

int64_t _1726_f(int64_t _1726_x){
    int64_t _1726_$retval;
    _1726_$retval = _1726_x;
    return _1726_$retval;
}


int main(void) {
  printf("%ld",_1724_main());
  return 0;
}

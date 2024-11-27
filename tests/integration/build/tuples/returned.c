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
    int64_t _0;
    int64_t _1;
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1865_main(void);
struct struct1 _1867_f(void);


/* Function definitions */
int64_t _1865_main(void){
    function0 _1865_t0;
    struct struct1 _1865_t1;
    int64_t _1865_$retval;
    _1865_t0 = (function0) _1867_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1865_t1 = _1865_t0();
    $line_idx--;
    _1865_$retval = _1865_t1._1;
    return _1865_$retval;
}

struct struct1 _1867_f(void){
    int64_t _1867_t1;
    int64_t _1867_t2;
    struct struct1 _1867_$retval;
    _1867_t1 = 45;
    _1867_t2 = 221;
    _1867_$retval = (struct struct1) {_1867_t1, _1867_t2};
    return _1867_$retval;
}


int main(void) {
  printf("%ld",_1865_main());
  return 0;
}

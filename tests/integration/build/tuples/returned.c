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
int64_t _1900_main(void);
struct struct1 _1902_f(void);


/* Function definitions */
int64_t _1900_main(void){
    function0 _1900_t0;
    struct struct1 _1900_t1;
    int64_t _1900_$retval;
    _1900_t0 = (function0) _1902_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1900_t1 = _1900_t0();
    $line_idx--;
    _1900_$retval = _1900_t1._1;
    return _1900_$retval;
}

struct struct1 _1902_f(void){
    int64_t _1902_t1;
    int64_t _1902_t2;
    struct struct1 _1902_$retval;
    _1902_t1 = 45;
    _1902_t2 = 221;
    _1902_$retval = (struct struct1) {_1902_t1, _1902_t2};
    return _1902_$retval;
}


int main(void) {
  printf("%ld",_1900_main());
  return 0;
}

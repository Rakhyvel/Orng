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
int64_t _1720_main(void);
struct struct1 _1722_f(void);


/* Function definitions */
int64_t _1720_main(void){
    function0 _1720_t0;
    struct struct1 _1720_t1;
    int64_t _1720_$retval;
    _1720_t0 = (function0) _1722_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1720_t1 = _1720_t0();
    $line_idx--;
    _1720_$retval = _1720_t1._1;
    return _1720_$retval;
}

struct struct1 _1722_f(void){
    int64_t _1722_t1;
    int64_t _1722_t2;
    struct struct1 _1722_$retval;
    _1722_t1 = 45;
    _1722_t2 = 221;
    _1722_$retval = (struct struct1) {_1722_t1, _1722_t2};
    return _1722_$retval;
}


int main(void) {
  printf("%ld",_1720_main());
  return 0;
}

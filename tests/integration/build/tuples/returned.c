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
int64_t _1765_main(void);
struct struct1 _1767_f(void);


/* Function definitions */
int64_t _1765_main(void){
    function0 _1765_t0;
    struct struct1 _1765_t1;
    int64_t _1765_$retval;
    _1765_t0 = (function0) _1767_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1765_t1 = _1765_t0();
    $line_idx--;
    _1765_$retval = _1765_t1._1;
    return _1765_$retval;
}

struct struct1 _1767_f(void){
    int64_t _1767_t1;
    int64_t _1767_t2;
    struct struct1 _1767_$retval;
    _1767_t1 = 45;
    _1767_t2 = 221;
    _1767_$retval = (struct struct1) {_1767_t1, _1767_t2};
    return _1767_$retval;
}


int main(void) {
  printf("%ld",_1765_main());
  return 0;
}

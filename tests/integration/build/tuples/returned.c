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
int64_t _1756_main(void);
struct struct1 _1758_f(void);


/* Function definitions */
int64_t _1756_main(void){
    function0 _1756_t0;
    struct struct1 _1756_t1;
    int64_t _1756_$retval;
    _1756_t0 = (function0) _1758_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1756_t1 = _1756_t0();
    $line_idx--;
    _1756_$retval = _1756_t1._1;
    return _1756_$retval;
}

struct struct1 _1758_f(void){
    int64_t _1758_t1;
    int64_t _1758_t2;
    struct struct1 _1758_$retval;
    _1758_t1 = 45;
    _1758_t2 = 221;
    _1758_$retval = (struct struct1) {_1758_t1, _1758_t2};
    return _1758_$retval;
}


int main(void) {
  printf("%ld",_1756_main());
  return 0;
}

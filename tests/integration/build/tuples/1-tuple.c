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
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1729_main(void);
struct struct1 _1731_get(void);


/* Function definitions */
int64_t _1729_main(void){
    function0 _1729_t0;
    struct struct1 _1729_t1;
    struct struct1 _1730_x;
    int64_t _1729_$retval;
    _1729_t0 = (function0) _1731_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1729_t1 = _1729_t0();
    $line_idx--;
    _1730_x = _1729_t1;
    _1729_$retval = _1730_x._0;
    return _1729_$retval;
}

struct struct1 _1731_get(void){
    int64_t _1731_t1;
    struct struct1 _1731_$retval;
    _1731_t1 = 234;
    _1731_$retval = (struct struct1) {_1731_t1};
    return _1731_$retval;
}


int main(void) {
  printf("%ld",_1729_main());
  return 0;
}

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
int64_t _1854_main(void);
struct struct1 _1856_get(void);


/* Function definitions */
int64_t _1854_main(void){
    function0 _1854_t0;
    struct struct1 _1854_t1;
    struct struct1 _1855_x;
    int64_t _1854_$retval;
    _1854_t0 = (function0) _1856_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1854_t1 = _1854_t0();
    $line_idx--;
    _1855_x = _1854_t1;
    _1854_$retval = _1855_x._0;
    return _1854_$retval;
}

struct struct1 _1856_get(void){
    int64_t _1856_t1;
    struct struct1 _1856_$retval;
    _1856_t1 = 234;
    _1856_$retval = (struct struct1) {_1856_t1};
    return _1856_$retval;
}


int main(void) {
  printf("%ld",_1854_main());
  return 0;
}

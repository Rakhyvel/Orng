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
int64_t _1657_main(void);
struct struct1 _1659_get(void);


/* Function definitions */
int64_t _1657_main(void){
    function0 _1657_t0;
    struct struct1 _1657_t1;
    struct struct1 _1658_x;
    int64_t _1657_$retval;
    _1657_t0 = (function0) _1659_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1657_t1 = _1657_t0();
    $line_idx--;
    _1658_x = _1657_t1;
    _1657_$retval = _1658_x._0;
    return _1657_$retval;
}

struct struct1 _1659_get(void){
    int64_t _1659_t1;
    struct struct1 _1659_$retval;
    _1659_t1 = 234;
    _1659_$retval = (struct struct1) {_1659_t1};
    return _1659_$retval;
}


int main(void) {
  printf("%ld",_1657_main());
  return 0;
}

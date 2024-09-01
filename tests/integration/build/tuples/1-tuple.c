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
int64_t _1768_main(void);
struct struct1 _1770_get(void);


/* Function definitions */
int64_t _1768_main(void){
    function0 _1768_t0;
    struct struct1 _1768_t1;
    struct struct1 _1769_x;
    int64_t _1768_$retval;
    _1768_t0 = (function0) _1770_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1768_t1 = _1768_t0();
    $line_idx--;
    _1769_x = _1768_t1;
    _1768_$retval = _1769_x._0;
    return _1768_$retval;
}

struct struct1 _1770_get(void){
    int64_t _1770_t1;
    struct struct1 _1770_$retval;
    _1770_t1 = 234;
    _1770_$retval = (struct struct1) {_1770_t1};
    return _1770_$retval;
}


int main(void) {
  printf("%ld",_1768_main());
  return 0;
}

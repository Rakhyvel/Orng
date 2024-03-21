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
int64_t _1715_main(void);
struct struct1 _1717_get(void);


/* Function definitions */
int64_t _1715_main(void){
    function0 _1715_t0;
    struct struct1 _1715_t1;
    struct struct1 _1716_x;
    int64_t _1715_$retval;
    _1715_t0 = (function0) _1717_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1715_t1 = _1715_t0();
    $line_idx--;
    _1716_x = _1715_t1;
    _1715_$retval = _1716_x._0;
    return _1715_$retval;
}

struct struct1 _1717_get(void){
    int64_t _1717_t1;
    struct struct1 _1717_$retval;
    _1717_t1 = 234;
    _1717_$retval = (struct struct1) {_1717_t1};
    return _1717_$retval;
}


int main(void) {
  printf("%ld",_1715_main());
  return 0;
}

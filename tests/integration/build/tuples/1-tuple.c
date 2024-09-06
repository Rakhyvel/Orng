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
int64_t _1794_main(void);
struct struct1 _1796_get(void);


/* Function definitions */
int64_t _1794_main(void){
    function0 _1794_t0;
    struct struct1 _1794_t1;
    struct struct1 _1795_x;
    int64_t _1794_$retval;
    _1794_t0 = (function0) _1796_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1794_t1 = _1794_t0();
    $line_idx--;
    _1795_x = _1794_t1;
    _1794_$retval = _1795_x._0;
    return _1794_$retval;
}

struct struct1 _1796_get(void){
    int64_t _1796_t1;
    struct struct1 _1796_$retval;
    _1796_t1 = 234;
    _1796_$retval = (struct struct1) {_1796_t1};
    return _1796_$retval;
}


int main(void) {
  printf("%ld",_1794_main());
  return 0;
}

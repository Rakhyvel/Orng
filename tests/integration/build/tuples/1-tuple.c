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
int64_t _1824_main(void);
struct struct1 _1826_get(void);


/* Function definitions */
int64_t _1824_main(void){
    function0 _1824_t0;
    struct struct1 _1824_t1;
    struct struct1 _1825_x;
    int64_t _1824_$retval;
    _1824_t0 = (function0) _1826_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1824_t1 = _1824_t0();
    $line_idx--;
    _1825_x = _1824_t1;
    _1824_$retval = _1825_x._0;
    return _1824_$retval;
}

struct struct1 _1826_get(void){
    int64_t _1826_t1;
    struct struct1 _1826_$retval;
    _1826_t1 = 234;
    _1826_$retval = (struct struct1) {_1826_t1};
    return _1826_$retval;
}


int main(void) {
  printf("%ld",_1824_main());
  return 0;
}

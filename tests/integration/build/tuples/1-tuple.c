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
int64_t _1779_main(void);
struct struct1 _1781_get(void);


/* Function definitions */
int64_t _1779_main(void){
    function0 _1779_t0;
    struct struct1 _1779_t1;
    struct struct1 _1780_x;
    int64_t _1779_$retval;
    _1779_t0 = (function0) _1781_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1779_t1 = _1779_t0();
    $line_idx--;
    _1780_x = _1779_t1;
    _1779_$retval = _1780_x._0;
    return _1779_$retval;
}

struct struct1 _1781_get(void){
    int64_t _1781_t1;
    struct struct1 _1781_$retval;
    _1781_t1 = 234;
    _1781_$retval = (struct struct1) {_1781_t1};
    return _1781_$retval;
}


int main(void) {
  printf("%ld",_1779_main());
  return 0;
}

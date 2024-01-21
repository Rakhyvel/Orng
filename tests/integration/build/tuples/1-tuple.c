/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int64_t _0;
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1518_main(void);
struct struct1 _1520_get(void);

/* Function definitions */
int64_t _1518_main(void){
    function0 _1518_t0;
    struct struct1 _1518_t1;
    struct struct1 _1519_x;
    int64_t _1518_$retval;
    _1518_t0 = _1520_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1518_t1 = _1518_t0();
    $line_idx--;
    _1519_x = _1518_t1;
    _1518_$retval = _1519_x._0;
    return _1518_$retval;
}

struct struct1 _1520_get(void){
    int64_t _1520_t1;
    struct struct1 _1520_$retval;
    _1520_t1 = 234;
    _1520_$retval = (struct struct1) {_1520_t1};
    return _1520_$retval;
}

int main(void) {
  printf("%ld",_1518_main());
  return 0;
}

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
int64_t _1485_main(void);
struct struct1 _1487_get(void);

/* Function definitions */
int64_t _1485_main(void){
    function0 _1485_t0;
    struct struct1 _1485_t1;
    struct struct1 _1486_x;
    int64_t _1485_$retval;
    _1485_t0 = _1487_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1485_t1 = _1485_t0();
    $line_idx--;
    _1486_x = _1485_t1;
    _1485_$retval = _1486_x._0;
    return _1485_$retval;
}

struct struct1 _1487_get(void){
    int64_t _1487_t1;
    struct struct1 _1487_$retval;
    _1487_t1 = 234;
    _1487_$retval = (struct struct1) {_1487_t1};
    return _1487_$retval;
}

int main(void) {
  printf("%ld",_1485_main());
  return 0;
}

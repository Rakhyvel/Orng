/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _1525_main(void);
struct1 _1527_get(void);

/* Function definitions */
int64_t _1525_main(void){
    function0 _1525_t0;
    struct1 _1525_t1;
    struct1 _1526_x;
    int64_t _1525_$retval;
    _1525_t0 = _1527_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1525_t1 = _1525_t0();
    $line_idx--;
    _1526_x = _1525_t1;
    _1525_$retval = _1526_x._0;
    return _1525_$retval;
}

struct1 _1527_get(void){
    int64_t _1527_t1;
    struct1 _1527_$retval;
    _1527_t1 = 234;
    _1527_$retval = (struct1) {_1527_t1};
    return _1527_$retval;
}

int main(void) {
  printf("%ld",_1525_main());
  return 0;
}

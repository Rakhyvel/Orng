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
int64_t _1482_main(void);
struct struct1 _1484_get(void);

/* Function definitions */
int64_t _1482_main(void){
    function0 _1482_t0;
    struct struct1 _1482_t1;
    struct struct1 _1483_x;
    int64_t _1482_$retval;
    _1482_t0 = _1484_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1482_t1 = _1482_t0();
    $line_idx--;
    _1483_x = _1482_t1;
    _1482_$retval = _1483_x._0;
    return _1482_$retval;
}

struct struct1 _1484_get(void){
    int64_t _1484_t1;
    struct struct1 _1484_$retval;
    _1484_t1 = 234;
    _1484_$retval = (struct struct1) {_1484_t1};
    return _1484_$retval;
}

int main(void) {
  printf("%ld",_1482_main());
  return 0;
}

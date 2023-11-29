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
int64_t _1481_main(void);
struct1 _1483_get(void);

/* Function definitions */
int64_t _1481_main(void) {
    function0 _1481_t0;
    struct1 _1481_t1;
    struct1 _1482_x;
    int64_t _1481_$retval;
    _1481_t0 = _1483_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1481_t1 = _1481_t0();
    $line_idx--;
    _1482_x = _1481_t1;
    _1481_$retval = _1482_x._0;
    return _1481_$retval;
}

struct1 _1483_get(void) {
    int64_t _1483_t1;
    struct1 _1483_$retval;
    _1483_t1 = 234;
    _1483_$retval = (struct1) {_1483_t1};
    return _1483_$retval;
}

int main(void) {
  printf("%ld",_1481_main());
  return 0;
}

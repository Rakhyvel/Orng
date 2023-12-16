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
int64_t _1446_main(void);
struct1 _1448_get(void);

/* Function definitions */
int64_t _1446_main(void) {
    function0 _1446_t0;
    struct1 _1446_t1;
    struct1 _1447_x;
    int64_t _1446_$retval;
    _1446_t0 = _1448_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1446_t1 = _1446_t0();
    $line_idx--;
    _1447_x = _1446_t1;
    _1446_$retval = _1447_x._0;
    return _1446_$retval;
}

struct1 _1448_get(void) {
    int64_t _1448_t1;
    struct1 _1448_$retval;
    _1448_t1 = 234;
    _1448_$retval = (struct1) {_1448_t1};
    return _1448_$retval;
}

int main(void) {
  printf("%ld",_1446_main());
  return 0;
}

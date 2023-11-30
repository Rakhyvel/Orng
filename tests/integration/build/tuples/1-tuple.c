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
int64_t _1460_main(void);
struct1 _1462_get(void);

/* Function definitions */
int64_t _1460_main(void) {
    function0 _1460_t0;
    struct1 _1460_t1;
    struct1 _1461_x;
    int64_t _1460_$retval;
    _1460_t0 = _1462_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1460_t1 = _1460_t0();
    $line_idx--;
    _1461_x = _1460_t1;
    _1460_$retval = _1461_x._0;
    return _1460_$retval;
}

struct1 _1462_get(void) {
    int64_t _1462_t1;
    struct1 _1462_$retval;
    _1462_t1 = 234;
    _1462_$retval = (struct1) {_1462_t1};
    return _1462_$retval;
}

int main(void) {
  printf("%ld",_1460_main());
  return 0;
}

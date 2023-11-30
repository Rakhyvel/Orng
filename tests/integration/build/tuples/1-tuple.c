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
int64_t _2_main(void);
struct1 _4_get(void);

/* Function definitions */
int64_t _2_main(void) {
    function0 _2_t0;
    struct1 _2_t1;
    struct1 _3_x;
    int64_t _2_$retval;
    _2_t0 = _4_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _2_t1 = _2_t0();
    $line_idx--;
    _3_x = _2_t1;
    _2_$retval = _3_x._0;
    return _2_$retval;
}

struct1 _4_get(void) {
    int64_t _4_t1;
    struct1 _4_$retval;
    _4_t1 = 234;
    _4_$retval = (struct1) {_4_t1};
    return _4_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}

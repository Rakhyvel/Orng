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
int64_t _1127_main(void);
struct1 _1129_get(void);

/* Function definitions */
int64_t _1127_main(void) {
    function0 _1127_t0;
    struct1 _1127_t1;
    struct1 _1128_x;
    int64_t _1127_$retval;
    _1127_t0 = _1129_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1127_t1 = _1127_t0();
    $line_idx--;
    _1128_x = _1127_t1;
    _1127_$retval = _1128_x._0;
    return _1127_$retval;
}

struct1 _1129_get(void) {
    int64_t _1129_t1;
    struct1 _1129_$retval;
    _1129_t1 = 234;
    _1129_$retval = (struct1) {_1129_t1};
    return _1129_$retval;
}

int main(void) {
  printf("%ld",_1127_main());
  return 0;
}

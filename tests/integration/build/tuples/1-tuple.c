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
int64_t _1184_main(void);
struct1 _1186_get(void);

/* Function definitions */
int64_t _1184_main(void) {
    function0 _1184_t0;
    struct1 _1184_t1;
    struct1 _1185_x;
    int64_t _1184_$retval;
    _1184_t0 = _1186_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1184_t1 = _1184_t0();
    $line_idx--;
    _1185_x = _1184_t1;
    _1184_$retval = _1185_x._0;
    return _1184_$retval;
}

struct1 _1186_get(void) {
    int64_t _1186_t1;
    struct1 _1186_$retval;
    _1186_t1 = 234;
    _1186_$retval = (struct1) {_1186_t1};
    return _1186_$retval;
}

int main(void) {
  printf("%ld",_1184_main());
  return 0;
}

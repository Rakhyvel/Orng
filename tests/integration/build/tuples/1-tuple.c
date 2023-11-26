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
int64_t _1037_main(void);
struct1 _1039_get(void);

/* Function definitions */
int64_t _1037_main(void) {
    function0 _1037_t0;
    struct1 _1037_t1;
    struct1 _1038_x;
    int64_t _1037_$retval;
    _1037_t0 = _1039_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1037_t1 = _1037_t0();
    $line_idx--;
    _1038_x = _1037_t1;
    _1037_$retval = _1038_x._0;
    return _1037_$retval;
}

struct1 _1039_get(void) {
    int64_t _1039_t1;
    struct1 _1039_$retval;
    _1039_t1 = 234;
    _1039_$retval = (struct1) {_1039_t1};
    return _1039_$retval;
}

int main(void) {
  printf("%ld",_1037_main());
  return 0;
}

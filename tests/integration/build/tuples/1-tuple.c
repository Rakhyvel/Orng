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
int64_t _1103_main(void);
struct1 _1105_get(void);

/* Function definitions */
int64_t _1103_main(void) {
    function0 _1103_t0;
    struct1 _1103_t1;
    struct1 _1104_x;
    int64_t _1103_$retval;
    _1103_t0 = _1105_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1103_t1 = _1103_t0();
    $line_idx--;
    _1104_x = _1103_t1;
    _1103_$retval = _1104_x._0;
    return _1103_$retval;
}

struct1 _1105_get(void) {
    int64_t _1105_t1;
    struct1 _1105_$retval;
    _1105_t1 = 234;
    _1105_$retval = (struct1) {_1105_t1};
    return _1105_$retval;
}

int main(void) {
  printf("%ld",_1103_main());
  return 0;
}

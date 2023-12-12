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
int64_t _1135_main(void);
struct1 _1137_get(void);

/* Function definitions */
int64_t _1135_main(void) {
    function0 _1135_t0;
    struct1 _1135_t1;
    struct1 _1136_x;
    int64_t _1135_$retval;
    _1135_t0 = _1137_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1135_t1 = _1135_t0();
    $line_idx--;
    _1136_x = _1135_t1;
    _1135_$retval = _1136_x._0;
    return _1135_$retval;
}

struct1 _1137_get(void) {
    int64_t _1137_t1;
    struct1 _1137_$retval;
    _1137_t1 = 234;
    _1137_$retval = (struct1) {_1137_t1};
    return _1137_$retval;
}

int main(void) {
  printf("%ld",_1135_main());
  return 0;
}

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
int64_t _1154_main(void);
struct1 _1156_get(void);

/* Function definitions */
int64_t _1154_main(void) {
    function0 _1154_t0;
    struct1 _1154_t1;
    struct1 _1155_x;
    int64_t _1154_$retval;
    _1154_t0 = _1156_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1154_t1 = _1154_t0();
    $line_idx--;
    _1155_x = _1154_t1;
    _1154_$retval = _1155_x._0;
    return _1154_$retval;
}

struct1 _1156_get(void) {
    int64_t _1156_t1;
    struct1 _1156_$retval;
    _1156_t1 = 234;
    _1156_$retval = (struct1) {_1156_t1};
    return _1156_$retval;
}

int main(void) {
  printf("%ld",_1154_main());
  return 0;
}

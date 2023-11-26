/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _25_main(void);
struct1 _27_f(void);

/* Function definitions */
int64_t _25_main(void) {
    function0 _25_t0;
    struct1 _25_t1;
    struct1 _26_x;
    int64_t _25_$retval;
    _25_t0 = _27_f;
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _25_t1 = _25_t0();
    $line_idx--;
    _26_x = _25_t1;
    _25_$retval = _26_x._1;
    return _25_$retval;
}

struct1 _27_f(void) {
    int64_t _27_t0;
    struct1 _27_$retval;
    _27_t0 = 4;
    _27_$retval = (struct1) {.tag=0, ._0=_27_t0};
    return _27_$retval;
}

int main(void) {
  printf("%ld",_25_main());
  return 0;
}

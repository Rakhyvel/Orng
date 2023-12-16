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
int64_t _1465_main(void);
struct1 _1467_get(void);

/* Function definitions */
int64_t _1465_main(void){
    function0 _1465_t0;
    struct1 _1465_t1;
    struct1 _1466_x;
    int64_t _1465_$retval;
    _1465_t0 = _1467_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1465_t1 = _1465_t0();
    $line_idx--;
    _1466_x = _1465_t1;
    _1465_$retval = _1466_x._0;
    return _1465_$retval;
}

struct1 _1467_get(void){
    int64_t _1467_t1;
    struct1 _1467_$retval;
    _1467_t1 = 234;
    _1467_$retval = (struct1) {_1467_t1};
    return _1467_$retval;
}

int main(void) {
  printf("%ld",_1465_main());
  return 0;
}

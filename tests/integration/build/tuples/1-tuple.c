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
int64_t _1709_main(void);
struct1 _1711_get(void);

/* Function definitions */
int64_t _1709_main(void){
    function0 _1709_t0;
    struct1 _1709_t1;
    struct1 _1710_x;
    int64_t _1709_$retval;
    _1709_t0 = _1711_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1709_t1 = _1709_t0();
    $line_idx--;
    _1710_x = _1709_t1;
    _1709_$retval = _1710_x._0;
    return _1709_$retval;
}

struct1 _1711_get(void){
    int64_t _1711_t1;
    struct1 _1711_$retval;
    _1711_t1 = 234;
    _1711_$retval = (struct1) {_1711_t1};
    return _1711_$retval;
}

int main(void) {
  printf("%ld",_1709_main());
  return 0;
}

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
int64_t _1699_main(void);
struct1 _1701_get(void);

/* Function definitions */
int64_t _1699_main(void){
    function0 _1699_t0;
    struct1 _1699_t1;
    struct1 _1700_x;
    int64_t _1699_$retval;
    _1699_t0 = _1701_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1699_t1 = _1699_t0();
    $line_idx--;
    _1700_x = _1699_t1;
    _1699_$retval = _1700_x._0;
    return _1699_$retval;
}

struct1 _1701_get(void){
    int64_t _1701_t1;
    struct1 _1701_$retval;
    _1701_t1 = 234;
    _1701_$retval = (struct1) {_1701_t1};
    return _1701_$retval;
}

int main(void) {
  printf("%ld",_1699_main());
  return 0;
}

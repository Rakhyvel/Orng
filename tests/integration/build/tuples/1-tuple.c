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
int64_t _1610_main(void);
struct1 _1612_get(void);

/* Function definitions */
int64_t _1610_main(void){
    function0 _1610_t0;
    struct1 _1610_t1;
    struct1 _1611_x;
    int64_t _1610_$retval;
    _1610_t0 = _1612_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1610_t1 = _1610_t0();
    $line_idx--;
    _1611_x = _1610_t1;
    _1610_$retval = _1611_x._0;
    return _1610_$retval;
}

struct1 _1612_get(void){
    int64_t _1612_t1;
    struct1 _1612_$retval;
    _1612_t1 = 234;
    _1612_$retval = (struct1) {_1612_t1};
    return _1612_$retval;
}

int main(void) {
  printf("%ld",_1610_main());
  return 0;
}

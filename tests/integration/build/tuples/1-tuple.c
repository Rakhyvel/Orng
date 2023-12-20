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
int64_t _1457_main(void);
struct1 _1459_get(void);

/* Function definitions */
int64_t _1457_main(void){
    function0 _1457_t0;
    struct1 _1457_t1;
    struct1 _1458_x;
    int64_t _1457_$retval;
    _1457_t0 = _1459_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1457_t1 = _1457_t0();
    $line_idx--;
    _1458_x = _1457_t1;
    _1457_$retval = _1458_x._0;
    return _1457_$retval;
}

struct1 _1459_get(void){
    int64_t _1459_t1;
    struct1 _1459_$retval;
    _1459_t1 = 234;
    _1459_$retval = (struct1) {_1459_t1};
    return _1459_$retval;
}

int main(void) {
  printf("%ld",_1457_main());
  return 0;
}

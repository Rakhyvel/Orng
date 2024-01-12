/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int64_t _0;
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1500_main(void);
struct struct1 _1502_get(void);

/* Function definitions */
int64_t _1500_main(void){
    function0 _1500_t0;
    struct struct1 _1500_t1;
    struct struct1 _1501_x;
    int64_t _1500_$retval;
    _1500_t0 = _1502_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1500_t1 = _1500_t0();
    $line_idx--;
    _1501_x = _1500_t1;
    _1500_$retval = _1501_x._0;
    return _1500_$retval;
}

struct struct1 _1502_get(void){
    int64_t _1502_t1;
    struct struct1 _1502_$retval;
    _1502_t1 = 234;
    _1502_$retval = (struct struct1) {_1502_t1};
    return _1502_$retval;
}

int main(void) {
  printf("%ld",_1500_main());
  return 0;
}

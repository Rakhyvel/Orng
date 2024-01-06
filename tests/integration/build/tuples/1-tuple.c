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
int64_t _1490_main(void);
struct struct1 _1492_get(void);

/* Function definitions */
int64_t _1490_main(void){
    function0 _1490_t0;
    struct struct1 _1490_t1;
    struct struct1 _1491_x;
    int64_t _1490_$retval;
    _1490_t0 = _1492_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1490_t1 = _1490_t0();
    $line_idx--;
    _1491_x = _1490_t1;
    _1490_$retval = _1491_x._0;
    return _1490_$retval;
}

struct struct1 _1492_get(void){
    int64_t _1492_t1;
    struct struct1 _1492_$retval;
    _1492_t1 = 234;
    _1492_$retval = (struct struct1) {_1492_t1};
    return _1492_$retval;
}

int main(void) {
  printf("%ld",_1490_main());
  return 0;
}

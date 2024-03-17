/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1691_main(void);
struct struct1 _1693_get(void);


/* Function definitions */
int64_t _1691_main(void){
    function0 _1691_t0;
    struct struct1 _1691_t1;
    struct struct1 _1692_x;
    int64_t _1691_$retval;
    _1691_t0 = (function0) _1693_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1691_t1 = _1691_t0();
    $line_idx--;
    _1692_x = _1691_t1;
    _1691_$retval = _1692_x._0;
    return _1691_$retval;
}

struct struct1 _1693_get(void){
    int64_t _1693_t1;
    struct struct1 _1693_$retval;
    _1693_t1 = 234;
    _1693_$retval = (struct struct1) {_1693_t1};
    return _1693_$retval;
}


int main(void) {
  printf("%ld",_1691_main());
  return 0;
}

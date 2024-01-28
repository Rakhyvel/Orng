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
int64_t _1633_main(void);
struct struct1 _1635_get(void);


/* Function definitions */
int64_t _1633_main(void){
    function0 _1633_t0;
    struct struct1 _1633_t1;
    struct struct1 _1634_x;
    int64_t _1633_$retval;
    _1633_t0 = _1635_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1633_t1 = _1633_t0();
    $line_idx--;
    _1634_x = _1633_t1;
    _1633_$retval = _1634_x._0;
    return _1633_$retval;
}

struct struct1 _1635_get(void){
    int64_t _1635_t1;
    struct struct1 _1635_$retval;
    _1635_t1 = 234;
    _1635_$retval = (struct struct1) {_1635_t1};
    return _1635_$retval;
}


int main(void) {
  printf("%ld",_1633_main());
  return 0;
}

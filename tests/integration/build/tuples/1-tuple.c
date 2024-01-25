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
int64_t _1589_main(void);
struct struct1 _1591_get(void);


/* Function definitions */
int64_t _1589_main(void){
    function0 _1589_t0;
    struct struct1 _1589_t1;
    struct struct1 _1590_x;
    int64_t _1589_$retval;
    _1589_t0 = _1591_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1589_t1 = _1589_t0();
    $line_idx--;
    _1590_x = _1589_t1;
    _1589_$retval = _1590_x._0;
    return _1589_$retval;
}

struct struct1 _1591_get(void){
    int64_t _1591_t1;
    struct struct1 _1591_$retval;
    _1591_t1 = 234;
    _1591_$retval = (struct struct1) {_1591_t1};
    return _1591_$retval;
}


int main(void) {
  printf("%ld",_1589_main());
  return 0;
}

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
int64_t _1787_main(void);
struct struct1 _1789_get(void);


/* Function definitions */
int64_t _1787_main(void){
    function0 _1787_t0;
    struct struct1 _1787_t1;
    struct struct1 _1788_x;
    int64_t _1787_$retval;
    _1787_t0 = (function0) _1789_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1787_t1 = _1787_t0();
    $line_idx--;
    _1788_x = _1787_t1;
    _1787_$retval = _1788_x._0;
    return _1787_$retval;
}

struct struct1 _1789_get(void){
    int64_t _1789_t1;
    struct struct1 _1789_$retval;
    _1789_t1 = 234;
    _1789_$retval = (struct struct1) {_1789_t1};
    return _1789_$retval;
}


int main(void) {
  printf("%ld",_1787_main());
  return 0;
}

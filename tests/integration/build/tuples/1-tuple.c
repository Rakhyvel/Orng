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
int64_t _1834_main(void);
struct struct1 _1836_get(void);


/* Function definitions */
int64_t _1834_main(void){
    function0 _1834_t0;
    struct struct1 _1834_t1;
    struct struct1 _1835_x;
    int64_t _1834_$retval;
    _1834_t0 = (function0) _1836_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1834_t1 = _1834_t0();
    $line_idx--;
    _1835_x = _1834_t1;
    _1834_$retval = _1835_x._0;
    return _1834_$retval;
}

struct struct1 _1836_get(void){
    int64_t _1836_t1;
    struct struct1 _1836_$retval;
    _1836_t1 = 234;
    _1836_$retval = (struct struct1) {_1836_t1};
    return _1836_$retval;
}


int main(void) {
  printf("%ld",_1834_main());
  return 0;
}

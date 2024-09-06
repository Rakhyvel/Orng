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
int64_t _1819_main(void);
struct struct1 _1821_get(void);


/* Function definitions */
int64_t _1819_main(void){
    function0 _1819_t0;
    struct struct1 _1819_t1;
    struct struct1 _1820_x;
    int64_t _1819_$retval;
    _1819_t0 = (function0) _1821_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1819_t1 = _1819_t0();
    $line_idx--;
    _1820_x = _1819_t1;
    _1819_$retval = _1820_x._0;
    return _1819_$retval;
}

struct struct1 _1821_get(void){
    int64_t _1821_t1;
    struct struct1 _1821_$retval;
    _1821_t1 = 234;
    _1821_$retval = (struct struct1) {_1821_t1};
    return _1821_$retval;
}


int main(void) {
  printf("%ld",_1819_main());
  return 0;
}

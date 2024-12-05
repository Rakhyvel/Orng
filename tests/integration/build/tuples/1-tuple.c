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
int64_t _1840_main(void);
struct struct1 _1842_get(void);


/* Function definitions */
int64_t _1840_main(void){
    function0 _1840_t0;
    struct struct1 _1840_t1;
    struct struct1 _1841_x;
    int64_t _1840_$retval;
    _1840_t0 = (function0) _1842_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1840_t1 = _1840_t0();
    $line_idx--;
    _1841_x = _1840_t1;
    _1840_$retval = _1841_x._0;
    return _1840_$retval;
}

struct struct1 _1842_get(void){
    int64_t _1842_t1;
    struct struct1 _1842_$retval;
    _1842_t1 = 234;
    _1842_$retval = (struct struct1) {_1842_t1};
    return _1842_$retval;
}


int main(void) {
  printf("%ld",_1840_main());
  return 0;
}

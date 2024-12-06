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
int64_t _1846_main(void);
struct struct1 _1848_get(void);


/* Function definitions */
int64_t _1846_main(void){
    function0 _1846_t0;
    struct struct1 _1846_t1;
    struct struct1 _1847_x;
    int64_t _1846_$retval;
    _1846_t0 = (function0) _1848_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1846_t1 = _1846_t0();
    $line_idx--;
    _1847_x = _1846_t1;
    _1846_$retval = _1847_x._0;
    return _1846_$retval;
}

struct struct1 _1848_get(void){
    int64_t _1848_t1;
    struct struct1 _1848_$retval;
    _1848_t1 = 234;
    _1848_$retval = (struct struct1) {_1848_t1};
    return _1848_$retval;
}


int main(void) {
  printf("%ld",_1846_main());
  return 0;
}

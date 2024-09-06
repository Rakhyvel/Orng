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
int64_t _1829_main(void);
struct struct1 _1831_get(void);


/* Function definitions */
int64_t _1829_main(void){
    function0 _1829_t0;
    struct struct1 _1829_t1;
    struct struct1 _1830_x;
    int64_t _1829_$retval;
    _1829_t0 = (function0) _1831_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1829_t1 = _1829_t0();
    $line_idx--;
    _1830_x = _1829_t1;
    _1829_$retval = _1830_x._0;
    return _1829_$retval;
}

struct struct1 _1831_get(void){
    int64_t _1831_t1;
    struct struct1 _1831_$retval;
    _1831_t1 = 234;
    _1831_$retval = (struct struct1) {_1831_t1};
    return _1831_$retval;
}


int main(void) {
  printf("%ld",_1829_main());
  return 0;
}

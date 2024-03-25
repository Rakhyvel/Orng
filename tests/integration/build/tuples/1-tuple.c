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
int64_t _1724_main(void);
struct struct1 _1726_get(void);


/* Function definitions */
int64_t _1724_main(void){
    function0 _1724_t0;
    struct struct1 _1724_t1;
    struct struct1 _1725_x;
    int64_t _1724_$retval;
    _1724_t0 = (function0) _1726_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1724_t1 = _1724_t0();
    $line_idx--;
    _1725_x = _1724_t1;
    _1724_$retval = _1725_x._0;
    return _1724_$retval;
}

struct struct1 _1726_get(void){
    int64_t _1726_t1;
    struct struct1 _1726_$retval;
    _1726_t1 = 234;
    _1726_$retval = (struct struct1) {_1726_t1};
    return _1726_$retval;
}


int main(void) {
  printf("%ld",_1724_main());
  return 0;
}

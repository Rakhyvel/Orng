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
int64_t _1562_main(void);
struct struct1 _1564_get(void);


/* Function definitions */
int64_t _1562_main(void){
    function0 _1562_t0;
    struct struct1 _1562_t1;
    struct struct1 _1563_x;
    int64_t _1562_$retval;
    _1562_t0 = _1564_get;
    $lines[$line_idx++] = "tests/integration/tuples/1-tuple.orng:3:17:\n    let x = get()\n               ^";
    _1562_t1 = _1562_t0();
    $line_idx--;
    _1563_x = _1562_t1;
    _1562_$retval = _1563_x._0;
    return _1562_$retval;
}

struct struct1 _1564_get(void){
    int64_t _1564_t1;
    struct struct1 _1564_$retval;
    _1564_t1 = 234;
    _1564_$retval = (struct struct1) {_1564_t1};
    return _1564_$retval;
}


int main(void) {
  printf("%ld",_1562_main());
  return 0;
}

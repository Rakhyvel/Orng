/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1559_main(void);
struct struct1 _1561_f(void);

/* Function definitions */
int64_t _1559_main(void){
    function0 _1559_t0;
    struct struct1 _1559_t1;
    int64_t _1559_$retval;
    _1559_t0 = _1561_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1559_t1 = _1559_t0();
    $line_idx--;
    _1559_$retval = _1559_t1._1;
    return _1559_$retval;
}

struct struct1 _1561_f(void){
    int64_t _1561_t1;
    int64_t _1561_t2;
    struct struct1 _1561_$retval;
    _1561_t1 = 45;
    _1561_t2 = 221;
    _1561_$retval = (struct struct1) {_1561_t1, _1561_t2};
    return _1561_$retval;
}

int main(void) {
  printf("%ld",_1559_main());
  return 0;
}

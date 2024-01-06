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
int64_t _1531_main(void);
struct struct1 _1533_f(void);

/* Function definitions */
int64_t _1531_main(void){
    function0 _1531_t0;
    struct struct1 _1531_t1;
    int64_t _1531_$retval;
    _1531_t0 = _1533_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1531_t1 = _1531_t0();
    $line_idx--;
    _1531_$retval = _1531_t1._1;
    return _1531_$retval;
}

struct struct1 _1533_f(void){
    int64_t _1533_t1;
    int64_t _1533_t2;
    struct struct1 _1533_$retval;
    _1533_t1 = 45;
    _1533_t2 = 221;
    _1533_$retval = (struct struct1) {_1533_t1, _1533_t2};
    return _1533_$retval;
}

int main(void) {
  printf("%ld",_1531_main());
  return 0;
}

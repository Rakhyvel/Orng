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
int64_t _1526_main(void);
struct struct1 _1528_f(void);

/* Function definitions */
int64_t _1526_main(void){
    function0 _1526_t0;
    struct struct1 _1526_t1;
    int64_t _1526_$retval;
    _1526_t0 = _1528_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1526_t1 = _1526_t0();
    $line_idx--;
    _1526_$retval = _1526_t1._1;
    return _1526_$retval;
}

struct struct1 _1528_f(void){
    int64_t _1528_t1;
    int64_t _1528_t2;
    struct struct1 _1528_$retval;
    _1528_t1 = 45;
    _1528_t2 = 221;
    _1528_$retval = (struct struct1) {_1528_t1, _1528_t2};
    return _1528_$retval;
}

int main(void) {
  printf("%ld",_1526_main());
  return 0;
}

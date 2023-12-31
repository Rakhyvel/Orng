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
int64_t _1523_main(void);
struct struct1 _1525_f(void);

/* Function definitions */
int64_t _1523_main(void){
    function0 _1523_t0;
    struct struct1 _1523_t1;
    int64_t _1523_$retval;
    _1523_t0 = _1525_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1523_t1 = _1523_t0();
    $line_idx--;
    _1523_$retval = _1523_t1._1;
    return _1523_$retval;
}

struct struct1 _1525_f(void){
    int64_t _1525_t1;
    int64_t _1525_t2;
    struct struct1 _1525_$retval;
    _1525_t1 = 45;
    _1525_t2 = 221;
    _1525_$retval = (struct struct1) {_1525_t1, _1525_t2};
    return _1525_$retval;
}

int main(void) {
  printf("%ld",_1523_main());
  return 0;
}

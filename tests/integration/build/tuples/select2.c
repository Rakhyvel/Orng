/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1559_main(void);
int64_t _1561_f(struct struct1 _1561_a);

/* Function definitions */
int64_t _1559_main(void){
    int64_t _1559_t2;
    int64_t _1559_t3;
    struct struct0 _1559_t1;
    int64_t _1559_t4;
    struct struct1 _1560_x;
    function2 _1559_t5;
    int64_t _1559_t6;
    int64_t _1559_$retval;
    _1559_t2 = 50;
    _1559_t3 = 150;
    _1559_t1 = (struct struct0) {_1559_t2, _1559_t3};
    _1559_t4 = 300;
    _1560_x = (struct struct1) {_1559_t1, _1559_t4};
    _1559_t5 = _1561_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1559_t6 = _1559_t5(_1560_x);
    $line_idx--;
    _1559_$retval = _1559_t6;
    return _1559_$retval;
}

int64_t _1561_f(struct struct1 _1561_a){
    int64_t _1561_$retval;
    _1561_$retval = _1561_a._1;
    return _1561_$retval;
}

int main(void) {
  printf("%ld",_1559_main());
  return 0;
}

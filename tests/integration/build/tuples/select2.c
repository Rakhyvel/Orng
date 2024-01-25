/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
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
int64_t _1648_main(void);
int64_t _1650_f(struct struct1 _1650_a);


/* Function definitions */
int64_t _1648_main(void){
    int64_t _1648_t2;
    int64_t _1648_t3;
    struct struct0 _1648_t1;
    int64_t _1648_t4;
    struct struct1 _1649_x;
    function2 _1648_t5;
    int64_t _1648_t6;
    int64_t _1648_$retval;
    _1648_t2 = 50;
    _1648_t3 = 150;
    _1648_t1 = (struct struct0) {_1648_t2, _1648_t3};
    _1648_t4 = 300;
    _1649_x = (struct struct1) {_1648_t1, _1648_t4};
    _1648_t5 = _1650_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1648_t6 = _1648_t5(_1649_x);
    $line_idx--;
    _1648_$retval = _1648_t6;
    return _1648_$retval;
}

int64_t _1650_f(struct struct1 _1650_a){
    int64_t _1650_$retval;
    _1650_$retval = _1650_a._1;
    return _1650_$retval;
}


int main(void) {
  printf("%ld",_1648_main());
  return 0;
}

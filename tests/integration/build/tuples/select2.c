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
int64_t _1750_main(void);
int64_t _1752_f(struct struct1 _1752_a);


/* Function definitions */
int64_t _1750_main(void){
    int64_t _1750_t2;
    int64_t _1750_t3;
    struct struct0 _1750_t1;
    int64_t _1750_t4;
    struct struct1 _1751_x;
    function2 _1750_t6;
    int64_t _1750_t7;
    int64_t _1750_$retval;
    _1750_t2 = 50;
    _1750_t3 = 150;
    _1750_t1 = (struct struct0) {_1750_t2, _1750_t3};
    _1750_t4 = 300;
    _1751_x = (struct struct1) {_1750_t1, _1750_t4};
    _1750_t6 = (function2) _1752_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1750_t7 = _1750_t6(_1751_x);
    $line_idx--;
    _1750_$retval = _1750_t7;
    return _1750_$retval;
}

int64_t _1752_f(struct struct1 _1752_a){
    int64_t _1752_$retval;
    _1752_$retval = _1752_a._1;
    return _1752_$retval;
}


int main(void) {
  printf("%ld",_1750_main());
  return 0;
}

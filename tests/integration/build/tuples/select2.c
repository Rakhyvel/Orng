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
int64_t _1853_main(void);
int64_t _1855_f(struct struct1 _1855_a);


/* Function definitions */
int64_t _1853_main(void){
    int64_t _1853_t2;
    int64_t _1853_t3;
    struct struct0 _1853_t1;
    int64_t _1853_t4;
    struct struct1 _1854_x;
    function2 _1853_t6;
    int64_t _1853_t7;
    int64_t _1853_$retval;
    _1853_t2 = 50;
    _1853_t3 = 150;
    _1853_t1 = (struct struct0) {_1853_t2, _1853_t3};
    _1853_t4 = 300;
    _1854_x = (struct struct1) {_1853_t1, _1853_t4};
    _1853_t6 = (function2) _1855_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1853_t7 = _1853_t6(_1854_x);
    $line_idx--;
    _1853_$retval = _1853_t7;
    return _1853_$retval;
}

int64_t _1855_f(struct struct1 _1855_a){
    int64_t _1855_$retval;
    goto BB2037;
BB2037:
    _1855_$retval = _1855_a._1;
    return _1855_$retval;
}


int main(void) {
  printf("%ld",_1853_main());
  return 0;
}

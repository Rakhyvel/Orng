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
int64_t _1878_main(void);
int64_t _1880_f(struct struct1 _1880_a);


/* Function definitions */
int64_t _1878_main(void){
    int64_t _1878_t2;
    int64_t _1878_t3;
    struct struct0 _1878_t1;
    int64_t _1878_t4;
    struct struct1 _1879_x;
    function2 _1878_t6;
    int64_t _1878_t7;
    int64_t _1878_$retval;
    _1878_t2 = 50;
    _1878_t3 = 150;
    _1878_t1 = (struct struct0) {_1878_t2, _1878_t3};
    _1878_t4 = 300;
    _1879_x = (struct struct1) {_1878_t1, _1878_t4};
    _1878_t6 = (function2) _1880_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1878_t7 = _1878_t6(_1879_x);
    $line_idx--;
    _1878_$retval = _1878_t7;
    return _1878_$retval;
}

int64_t _1880_f(struct struct1 _1880_a){
    int64_t _1880_$retval;
    goto BB2037;
BB2037:
    _1880_$retval = _1880_a._1;
    return _1880_$retval;
}


int main(void) {
  printf("%ld",_1878_main());
  return 0;
}

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
int64_t _1692_main(void);
int64_t _1694_f(struct struct1 _1694_a);


/* Function definitions */
int64_t _1692_main(void){
    int64_t _1692_t2;
    int64_t _1692_t3;
    struct struct0 _1692_t1;
    int64_t _1692_t4;
    struct struct1 _1693_x;
    function2 _1692_t5;
    int64_t _1692_t6;
    int64_t _1692_$retval;
    _1692_t2 = 50;
    _1692_t3 = 150;
    _1692_t1 = (struct struct0) {_1692_t2, _1692_t3};
    _1692_t4 = 300;
    _1693_x = (struct struct1) {_1692_t1, _1692_t4};
    _1692_t5 = _1694_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1692_t6 = _1692_t5(_1693_x);
    $line_idx--;
    _1692_$retval = _1692_t6;
    return _1692_$retval;
}

int64_t _1694_f(struct struct1 _1694_a){
    int64_t _1694_$retval;
    _1694_$retval = _1694_a._1;
    return _1694_$retval;
}


int main(void) {
  printf("%ld",_1692_main());
  return 0;
}

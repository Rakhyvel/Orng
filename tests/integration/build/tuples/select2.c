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
int64_t _1772_main(void);
int64_t _1774_f(struct struct1 _1774_a);


/* Function definitions */
int64_t _1772_main(void){
    int64_t _1772_t2;
    int64_t _1772_t3;
    struct struct0 _1772_t1;
    int64_t _1772_t4;
    struct struct1 _1773_x;
    function2 _1772_t6;
    int64_t _1772_t7;
    int64_t _1772_$retval;
    _1772_t2 = 50;
    _1772_t3 = 150;
    _1772_t1 = (struct struct0) {_1772_t2, _1772_t3};
    _1772_t4 = 300;
    _1773_x = (struct struct1) {_1772_t1, _1772_t4};
    _1772_t6 = (function2) _1774_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1772_t7 = _1772_t6(_1773_x);
    $line_idx--;
    _1772_$retval = _1772_t7;
    return _1772_$retval;
}

int64_t _1774_f(struct struct1 _1774_a){
    int64_t _1774_$retval;
    _1774_$retval = _1774_a._1;
    return _1774_$retval;
}


int main(void) {
  printf("%ld",_1772_main());
  return 0;
}

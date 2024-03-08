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
int64_t _1716_main(void);
int64_t _1718_f(struct struct1 _1718_a);


/* Function definitions */
int64_t _1716_main(void){
    int64_t _1716_t2;
    int64_t _1716_t3;
    struct struct0 _1716_t1;
    int64_t _1716_t4;
    struct struct1 _1717_x;
    function2 _1716_t5;
    int64_t _1716_t6;
    int64_t _1716_$retval;
    _1716_t2 = 50;
    _1716_t3 = 150;
    _1716_t1 = (struct struct0) {_1716_t2, _1716_t3};
    _1716_t4 = 300;
    _1717_x = (struct struct1) {_1716_t1, _1716_t4};
    _1716_t5 = (function2) _1718_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1716_t6 = _1716_t5(_1717_x);
    $line_idx--;
    _1716_$retval = _1716_t6;
    return _1716_$retval;
}

int64_t _1718_f(struct struct1 _1718_a){
    int64_t _1718_$retval;
    _1718_$retval = _1718_a._1;
    return _1718_$retval;
}


int main(void) {
  printf("%ld",_1716_main());
  return 0;
}

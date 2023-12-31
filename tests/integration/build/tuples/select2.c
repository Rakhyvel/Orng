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
int64_t _1541_main(void);
int64_t _1543_f(struct struct1 _1543_a);

/* Function definitions */
int64_t _1541_main(void){
    int64_t _1541_t2;
    int64_t _1541_t3;
    struct struct0 _1541_t1;
    int64_t _1541_t4;
    struct struct1 _1542_x;
    function2 _1541_t5;
    int64_t _1541_t6;
    int64_t _1541_$retval;
    _1541_t2 = 50;
    _1541_t3 = 150;
    _1541_t1 = (struct struct0) {_1541_t2, _1541_t3};
    _1541_t4 = 300;
    _1542_x = (struct struct1) {_1541_t1, _1541_t4};
    _1541_t5 = _1543_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1541_t6 = _1541_t5(_1542_x);
    $line_idx--;
    _1541_$retval = _1541_t6;
    return _1541_$retval;
}

int64_t _1543_f(struct struct1 _1543_a){
    int64_t _1543_$retval;
    _1543_$retval = _1543_a._1;
    return _1543_$retval;
}

int main(void) {
  printf("%ld",_1541_main());
  return 0;
}

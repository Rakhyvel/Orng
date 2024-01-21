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
int64_t _1577_main(void);
int64_t _1579_f(struct struct1 _1579_a);

/* Function definitions */
int64_t _1577_main(void){
    int64_t _1577_t2;
    int64_t _1577_t3;
    struct struct0 _1577_t1;
    int64_t _1577_t4;
    struct struct1 _1578_x;
    function2 _1577_t5;
    int64_t _1577_t6;
    int64_t _1577_$retval;
    _1577_t2 = 50;
    _1577_t3 = 150;
    _1577_t1 = (struct struct0) {_1577_t2, _1577_t3};
    _1577_t4 = 300;
    _1578_x = (struct struct1) {_1577_t1, _1577_t4};
    _1577_t5 = _1579_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1577_t6 = _1577_t5(_1578_x);
    $line_idx--;
    _1577_$retval = _1577_t6;
    return _1577_$retval;
}

int64_t _1579_f(struct struct1 _1579_a){
    int64_t _1579_$retval;
    _1579_$retval = _1579_a._1;
    return _1579_$retval;
}

int main(void) {
  printf("%ld",_1577_main());
  return 0;
}

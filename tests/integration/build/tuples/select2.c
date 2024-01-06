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
int64_t _1549_main(void);
int64_t _1551_f(struct struct1 _1551_a);

/* Function definitions */
int64_t _1549_main(void){
    int64_t _1549_t2;
    int64_t _1549_t3;
    struct struct0 _1549_t1;
    int64_t _1549_t4;
    struct struct1 _1550_x;
    function2 _1549_t5;
    int64_t _1549_t6;
    int64_t _1549_$retval;
    _1549_t2 = 50;
    _1549_t3 = 150;
    _1549_t1 = (struct struct0) {_1549_t2, _1549_t3};
    _1549_t4 = 300;
    _1550_x = (struct struct1) {_1549_t1, _1549_t4};
    _1549_t5 = _1551_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1549_t6 = _1549_t5(_1550_x);
    $line_idx--;
    _1549_$retval = _1549_t6;
    return _1549_$retval;
}

int64_t _1551_f(struct struct1 _1551_a){
    int64_t _1551_$retval;
    _1551_$retval = _1551_a._1;
    return _1551_$retval;
}

int main(void) {
  printf("%ld",_1549_main());
  return 0;
}

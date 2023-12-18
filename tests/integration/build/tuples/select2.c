/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

typedef struct {
    struct0 _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1788_main(void);
int64_t _1790_f(struct1 _1790_a);

/* Function definitions */
int64_t _1788_main(void){
    int64_t _1788_t2;
    int64_t _1788_t3;
    struct0 _1788_t1;
    int64_t _1788_t4;
    struct1 _1789_x;
    function2 _1788_t5;
    int64_t _1788_t6;
    int64_t _1788_$retval;
    _1788_t2 = 50;
    _1788_t3 = 150;
    _1788_t1 = (struct0) {_1788_t2, _1788_t3};
    _1788_t4 = 300;
    _1789_x = (struct1) {_1788_t1, _1788_t4};
    _1788_t5 = _1790_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1788_t6 = _1788_t5(_1789_x);
    $line_idx--;
    _1788_$retval = _1788_t6;
    return _1788_$retval;
}

int64_t _1790_f(struct1 _1790_a){
    int64_t _1790_$retval;
    _1790_$retval = _1790_a._1;
    return _1790_$retval;
}

int main(void) {
  printf("%ld",_1788_main());
  return 0;
}

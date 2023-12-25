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
        int64_t _2;
} struct1;

typedef int64_t(*function0)(struct1*);

/* Function forward definitions */
int64_t _11_main(void);
int64_t _13_sum(struct1* _13_xs);

/* Function definitions */
int64_t _11_main(void){
    function0 _11_t0;
    int64_t _11_t3;
    int64_t _11_t4;
    int64_t _11_t5;
    struct1 _11_t2;
    struct1* _11_t6;
    int64_t _11_t1;
    int64_t _11_$retval;
    _11_t0 = _13_sum;
    _11_t3 = 200;
    _11_t4 = 0;
    _11_t5 = 9;
    _11_t2 = (struct1) {_11_t3, _11_t4, _11_t5};
    _11_t6 = &_11_t2;
    $lines[$line_idx++] = "tests/integration/arrays/addr-of-array.orng:3:9:\n    sum(&(200, 0, 9)) // Address of product literal\n       ^";
    _11_t1 = _11_t0(_11_t6);
    $line_idx--;
    _11_$retval = _11_t1;
    return _11_$retval;
}

int64_t _13_sum(struct1* _13_xs){
    int64_t _13_t0;
    int64_t _13_t1;
    int64_t _13_t2;
    int64_t _13_t3;
    int64_t _13_t4;
    int64_t _13_t5;
    int64_t _13_t6;
    int64_t _13_$retval;
    _13_t0 = 0;
    _13_t1 = 3;
    _13_t2 = 1;
    _13_t3 = 3;
    $bounds_check(_13_t0, _13_t1, "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    $bounds_check(_13_t2, _13_t3, "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _13_t4 = $add_int64_t(*((int64_t*)_13_xs + _13_t0), *((int64_t*)_13_xs + _13_t2), "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _13_t5 = 2;
    _13_t6 = 3;
    $bounds_check(_13_t5, _13_t6, "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    _13_$retval = $add_int64_t(_13_t4, *((int64_t*)_13_xs + _13_t5), "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    return _13_$retval;
}

int main(void) {
  printf("%ld",_11_main());
  return 0;
}

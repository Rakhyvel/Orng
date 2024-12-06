/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct3;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

struct struct2 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

typedef struct struct2(*function0)(int64_t, int64_t);

struct struct3 {
    int64_t _0;
    int64_t* _1;
};

/* Function forward definitions */
int64_t _1875_main(void);
struct struct2 _1877_get_array(int64_t _1877_a, int64_t _1877_b);


/* Function definitions */
int64_t _1875_main(void){
    function0 _1875_t0;
    int64_t _1875_t2;
    int64_t _1875_t3;
    int64_t _1876_z;
    int64_t* _1875_t9;
    struct struct3 _1876_y;
    int64_t _1875_$retval;
    _1875_t0 = (function0) _1877_get_array;
    _1875_t2 = 15;
    _1875_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1875_t0(_1875_t2, _1875_t3);
    $line_idx--;
    _1876_z = 64;
    _1875_t9 = &_1876_z;
    _1876_y = (struct struct3) {_1876_z, _1875_t9};
    _1875_$retval = _1876_y._0;
    return _1875_$retval;
}

struct struct2 _1877_get_array(int64_t _1877_a, int64_t _1877_b){
    struct struct2 _1877_$retval;
    _1877_$retval = (struct struct2) {_1877_a, _1877_b, _1877_a, _1877_b};
    return _1877_$retval;
}


int main(void) {
  printf("%ld",_1875_main());
  return 0;
}

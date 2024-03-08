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
int64_t _1686_main(void);
struct struct2 _1688_get_array(int64_t _1688_a, int64_t _1688_b);


/* Function definitions */
int64_t _1686_main(void){
    function0 _1686_t0;
    int64_t _1686_t2;
    int64_t _1686_t3;
    int64_t _1687_z;
    int64_t* _1686_t7;
    struct struct3 _1687_y;
    int64_t _1686_$retval;
    _1686_t0 = (function0) _1688_get_array;
    _1686_t2 = 15;
    _1686_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1686_t0(_1686_t2, _1686_t3);
    $line_idx--;
    _1687_z = 64;
    _1686_t7 = &_1687_z;
    _1687_y = (struct struct3) {_1687_z, _1686_t7};
    _1686_$retval = _1687_y._0;
    return _1686_$retval;
}

struct struct2 _1688_get_array(int64_t _1688_a, int64_t _1688_b){
    struct struct2 _1688_$retval;
    _1688_$retval = (struct struct2) {_1688_a, _1688_b, _1688_a, _1688_b};
    return _1688_$retval;
}


int main(void) {
  printf("%ld",_1686_main());
  return 0;
}

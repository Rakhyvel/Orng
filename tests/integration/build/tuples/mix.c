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
int64_t _1744_main(void);
struct struct2 _1746_get_array(int64_t _1746_a, int64_t _1746_b);


/* Function definitions */
int64_t _1744_main(void){
    function0 _1744_t0;
    int64_t _1744_t2;
    int64_t _1744_t3;
    int64_t _1745_z;
    int64_t* _1744_t9;
    struct struct3 _1745_y;
    int64_t _1744_$retval;
    _1744_t0 = (function0) _1746_get_array;
    _1744_t2 = 15;
    _1744_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1744_t0(_1744_t2, _1744_t3);
    $line_idx--;
    _1745_z = 64;
    _1744_t9 = &_1745_z;
    _1745_y = (struct struct3) {_1745_z, _1744_t9};
    _1744_$retval = _1745_y._0;
    return _1744_$retval;
}

struct struct2 _1746_get_array(int64_t _1746_a, int64_t _1746_b){
    struct struct2 _1746_$retval;
    _1746_$retval = (struct struct2) {_1746_a, _1746_b, _1746_a, _1746_b};
    return _1746_$retval;
}


int main(void) {
  printf("%ld",_1744_main());
  return 0;
}

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
int64_t _1753_main(void);
struct struct2 _1755_get_array(int64_t _1755_a, int64_t _1755_b);


/* Function definitions */
int64_t _1753_main(void){
    function0 _1753_t0;
    int64_t _1753_t2;
    int64_t _1753_t3;
    int64_t _1754_z;
    int64_t* _1753_t9;
    struct struct3 _1754_y;
    int64_t _1753_$retval;
    _1753_t0 = (function0) _1755_get_array;
    _1753_t2 = 15;
    _1753_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1753_t0(_1753_t2, _1753_t3);
    $line_idx--;
    _1754_z = 64;
    _1753_t9 = &_1754_z;
    _1754_y = (struct struct3) {_1754_z, _1753_t9};
    _1753_$retval = _1754_y._0;
    return _1753_$retval;
}

struct struct2 _1755_get_array(int64_t _1755_a, int64_t _1755_b){
    struct struct2 _1755_$retval;
    _1755_$retval = (struct struct2) {_1755_a, _1755_b, _1755_a, _1755_b};
    return _1755_$retval;
}


int main(void) {
  printf("%ld",_1753_main());
  return 0;
}

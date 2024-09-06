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
int64_t _1855_main(void);
struct struct2 _1857_get_array(int64_t _1857_a, int64_t _1857_b);


/* Function definitions */
int64_t _1855_main(void){
    function0 _1855_t0;
    int64_t _1855_t2;
    int64_t _1855_t3;
    int64_t _1856_z;
    int64_t* _1855_t9;
    struct struct3 _1856_y;
    int64_t _1855_$retval;
    _1855_t0 = (function0) _1857_get_array;
    _1855_t2 = 15;
    _1855_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1855_t0(_1855_t2, _1855_t3);
    $line_idx--;
    _1856_z = 64;
    _1855_t9 = &_1856_z;
    _1856_y = (struct struct3) {_1856_z, _1855_t9};
    _1855_$retval = _1856_y._0;
    return _1855_$retval;
}

struct struct2 _1857_get_array(int64_t _1857_a, int64_t _1857_b){
    struct struct2 _1857_$retval;
    _1857_$retval = (struct struct2) {_1857_a, _1857_b, _1857_a, _1857_b};
    return _1857_$retval;
}


int main(void) {
  printf("%ld",_1855_main());
  return 0;
}

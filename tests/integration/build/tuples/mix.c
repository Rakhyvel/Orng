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
int64_t _1808_main(void);
struct struct2 _1810_get_array(int64_t _1810_a, int64_t _1810_b);


/* Function definitions */
int64_t _1808_main(void){
    function0 _1808_t0;
    int64_t _1808_t2;
    int64_t _1808_t3;
    int64_t _1809_z;
    int64_t* _1808_t9;
    struct struct3 _1809_y;
    int64_t _1808_$retval;
    _1808_t0 = (function0) _1810_get_array;
    _1808_t2 = 15;
    _1808_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1808_t0(_1808_t2, _1808_t3);
    $line_idx--;
    _1809_z = 64;
    _1808_t9 = &_1809_z;
    _1809_y = (struct struct3) {_1809_z, _1808_t9};
    _1808_$retval = _1809_y._0;
    return _1808_$retval;
}

struct struct2 _1810_get_array(int64_t _1810_a, int64_t _1810_b){
    struct struct2 _1810_$retval;
    _1810_$retval = (struct struct2) {_1810_a, _1810_b, _1810_a, _1810_b};
    return _1810_$retval;
}


int main(void) {
  printf("%ld",_1808_main());
  return 0;
}

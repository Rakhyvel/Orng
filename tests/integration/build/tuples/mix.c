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
int64_t _1708_main(void);
struct struct2 _1710_get_array(int64_t _1710_a, int64_t _1710_b);


/* Function definitions */
int64_t _1708_main(void){
    function0 _1708_t0;
    int64_t _1708_t2;
    int64_t _1708_t3;
    int64_t _1709_z;
    int64_t* _1708_t9;
    struct struct3 _1709_y;
    int64_t _1708_$retval;
    _1708_t0 = (function0) _1710_get_array;
    _1708_t2 = 15;
    _1708_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1708_t0(_1708_t2, _1708_t3);
    $line_idx--;
    _1709_z = 64;
    _1708_t9 = &_1709_z;
    _1709_y = (struct struct3) {_1709_z, _1708_t9};
    _1708_$retval = _1709_y._0;
    return _1708_$retval;
}

struct struct2 _1710_get_array(int64_t _1710_a, int64_t _1710_b){
    struct struct2 _1710_$retval;
    _1710_$retval = (struct struct2) {_1710_a, _1710_b, _1710_a, _1710_b};
    return _1710_$retval;
}


int main(void) {
  printf("%ld",_1708_main());
  return 0;
}

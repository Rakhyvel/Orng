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
int64_t _1903_main(void);
struct struct2 _1905_get_array(int64_t _1905_a, int64_t _1905_b);


/* Function definitions */
int64_t _1903_main(void){
    function0 _1903_t0;
    int64_t _1903_t2;
    int64_t _1903_t3;
    int64_t _1904_z;
    int64_t* _1903_t9;
    struct struct3 _1904_y;
    int64_t _1903_$retval;
    _1903_t0 = (function0) _1905_get_array;
    _1903_t2 = 15;
    _1903_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1903_t0(_1903_t2, _1903_t3);
    $line_idx--;
    _1904_z = 64;
    _1903_t9 = &_1904_z;
    _1904_y = (struct struct3) {_1904_z, _1903_t9};
    _1903_$retval = _1904_y._0;
    return _1903_$retval;
}

struct struct2 _1905_get_array(int64_t _1905_a, int64_t _1905_b){
    struct struct2 _1905_$retval;
    _1905_$retval = (struct struct2) {_1905_a, _1905_b, _1905_a, _1905_b};
    return _1905_$retval;
}


int main(void) {
  printf("%ld",_1903_main());
  return 0;
}

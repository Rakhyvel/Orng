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
int64_t _1869_main(void);
struct struct2 _1871_get_array(int64_t _1871_a, int64_t _1871_b);


/* Function definitions */
int64_t _1869_main(void){
    function0 _1869_t0;
    int64_t _1869_t2;
    int64_t _1869_t3;
    int64_t _1870_z;
    int64_t* _1869_t9;
    struct struct3 _1870_y;
    int64_t _1869_$retval;
    _1869_t0 = (function0) _1871_get_array;
    _1869_t2 = 15;
    _1869_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1869_t0(_1869_t2, _1869_t3);
    $line_idx--;
    _1870_z = 64;
    _1869_t9 = &_1870_z;
    _1870_y = (struct struct3) {_1870_z, _1869_t9};
    _1869_$retval = _1870_y._0;
    return _1869_$retval;
}

struct struct2 _1871_get_array(int64_t _1871_a, int64_t _1871_b){
    struct struct2 _1871_$retval;
    _1871_$retval = (struct struct2) {_1871_a, _1871_b, _1871_a, _1871_b};
    return _1871_$retval;
}


int main(void) {
  printf("%ld",_1869_main());
  return 0;
}

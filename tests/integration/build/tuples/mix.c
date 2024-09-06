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
int64_t _1816_main(void);
struct struct2 _1818_get_array(int64_t _1818_a, int64_t _1818_b);


/* Function definitions */
int64_t _1816_main(void){
    function0 _1816_t0;
    int64_t _1816_t2;
    int64_t _1816_t3;
    int64_t _1817_z;
    int64_t* _1816_t9;
    struct struct3 _1817_y;
    int64_t _1816_$retval;
    _1816_t0 = (function0) _1818_get_array;
    _1816_t2 = 15;
    _1816_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1816_t0(_1816_t2, _1816_t3);
    $line_idx--;
    _1817_z = 64;
    _1816_t9 = &_1817_z;
    _1817_y = (struct struct3) {_1817_z, _1816_t9};
    _1816_$retval = _1817_y._0;
    return _1816_$retval;
}

struct struct2 _1818_get_array(int64_t _1818_a, int64_t _1818_b){
    struct struct2 _1818_$retval;
    _1818_$retval = (struct struct2) {_1818_a, _1818_b, _1818_a, _1818_b};
    return _1818_$retval;
}


int main(void) {
  printf("%ld",_1816_main());
  return 0;
}

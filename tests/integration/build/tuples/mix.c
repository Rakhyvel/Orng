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
int64_t _1742_main(void);
struct struct2 _1744_get_array(int64_t _1744_a, int64_t _1744_b);


/* Function definitions */
int64_t _1742_main(void){
    function0 _1742_t0;
    int64_t _1742_t2;
    int64_t _1742_t3;
    int64_t _1743_z;
    int64_t* _1742_t9;
    struct struct3 _1743_y;
    int64_t _1742_$retval;
    _1742_t0 = (function0) _1744_get_array;
    _1742_t2 = 15;
    _1742_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1742_t0(_1742_t2, _1742_t3);
    $line_idx--;
    _1743_z = 64;
    _1742_t9 = &_1743_z;
    _1743_y = (struct struct3) {_1743_z, _1742_t9};
    _1742_$retval = _1743_y._0;
    return _1742_$retval;
}

struct struct2 _1744_get_array(int64_t _1744_a, int64_t _1744_b){
    struct struct2 _1744_$retval;
    _1744_$retval = (struct struct2) {_1744_a, _1744_b, _1744_a, _1744_b};
    return _1744_$retval;
}


int main(void) {
  printf("%ld",_1742_main());
  return 0;
}

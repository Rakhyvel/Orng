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
int64_t _1720_main(void);
struct struct2 _1722_get_array(int64_t _1722_a, int64_t _1722_b);


/* Function definitions */
int64_t _1720_main(void){
    function0 _1720_t0;
    int64_t _1720_t2;
    int64_t _1720_t3;
    int64_t _1721_z;
    int64_t* _1720_t9;
    struct struct3 _1721_y;
    int64_t _1720_$retval;
    _1720_t0 = (function0) _1722_get_array;
    _1720_t2 = 15;
    _1720_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1720_t0(_1720_t2, _1720_t3);
    $line_idx--;
    _1721_z = 64;
    _1720_t9 = &_1721_z;
    _1721_y = (struct struct3) {_1721_z, _1720_t9};
    _1720_$retval = _1721_y._0;
    return _1720_$retval;
}

struct struct2 _1722_get_array(int64_t _1722_a, int64_t _1722_b){
    struct struct2 _1722_$retval;
    _1722_$retval = (struct struct2) {_1722_a, _1722_b, _1722_a, _1722_b};
    return _1722_$retval;
}


int main(void) {
  printf("%ld",_1720_main());
  return 0;
}

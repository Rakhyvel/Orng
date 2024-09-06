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
int64_t _1858_main(void);
struct struct2 _1860_get_array(int64_t _1860_a, int64_t _1860_b);


/* Function definitions */
int64_t _1858_main(void){
    function0 _1858_t0;
    int64_t _1858_t2;
    int64_t _1858_t3;
    int64_t _1859_z;
    int64_t* _1858_t9;
    struct struct3 _1859_y;
    int64_t _1858_$retval;
    _1858_t0 = (function0) _1860_get_array;
    _1858_t2 = 15;
    _1858_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1858_t0(_1858_t2, _1858_t3);
    $line_idx--;
    _1859_z = 64;
    _1858_t9 = &_1859_z;
    _1859_y = (struct struct3) {_1859_z, _1858_t9};
    _1858_$retval = _1859_y._0;
    return _1858_$retval;
}

struct struct2 _1860_get_array(int64_t _1860_a, int64_t _1860_b){
    struct struct2 _1860_$retval;
    _1860_$retval = (struct struct2) {_1860_a, _1860_b, _1860_a, _1860_b};
    return _1860_$retval;
}


int main(void) {
  printf("%ld",_1858_main());
  return 0;
}

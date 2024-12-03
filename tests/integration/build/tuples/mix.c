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
int64_t _1863_main(void);
struct struct2 _1865_get_array(int64_t _1865_a, int64_t _1865_b);


/* Function definitions */
int64_t _1863_main(void){
    function0 _1863_t0;
    int64_t _1863_t2;
    int64_t _1863_t3;
    int64_t _1864_z;
    int64_t* _1863_t9;
    struct struct3 _1864_y;
    int64_t _1863_$retval;
    _1863_t0 = (function0) _1865_get_array;
    _1863_t2 = 15;
    _1863_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1863_t0(_1863_t2, _1863_t3);
    $line_idx--;
    _1864_z = 64;
    _1863_t9 = &_1864_z;
    _1864_y = (struct struct3) {_1864_z, _1863_t9};
    _1863_$retval = _1864_y._0;
    return _1863_$retval;
}

struct struct2 _1865_get_array(int64_t _1865_a, int64_t _1865_b){
    struct struct2 _1865_$retval;
    _1865_$retval = (struct struct2) {_1865_a, _1865_b, _1865_a, _1865_b};
    return _1865_$retval;
}


int main(void) {
  printf("%ld",_1863_main());
  return 0;
}

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
int64_t _1883_main(void);
struct struct2 _1885_get_array(int64_t _1885_a, int64_t _1885_b);


/* Function definitions */
int64_t _1883_main(void){
    function0 _1883_t0;
    int64_t _1883_t2;
    int64_t _1883_t3;
    int64_t _1884_z;
    int64_t* _1883_t9;
    struct struct3 _1884_y;
    int64_t _1883_$retval;
    _1883_t0 = (function0) _1885_get_array;
    _1883_t2 = 15;
    _1883_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1883_t0(_1883_t2, _1883_t3);
    $line_idx--;
    _1884_z = 64;
    _1883_t9 = &_1884_z;
    _1884_y = (struct struct3) {_1884_z, _1883_t9};
    _1883_$retval = _1884_y._0;
    return _1883_$retval;
}

struct struct2 _1885_get_array(int64_t _1885_a, int64_t _1885_b){
    struct struct2 _1885_$retval;
    _1885_$retval = (struct struct2) {_1885_a, _1885_b, _1885_a, _1885_b};
    return _1885_$retval;
}


int main(void) {
  printf("%ld",_1883_main());
  return 0;
}

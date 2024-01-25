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
int64_t _1618_main(void);
struct struct2 _1620_get_array(int64_t _1620_a, int64_t _1620_b);


/* Function definitions */
int64_t _1618_main(void){
    function0 _1618_t0;
    int64_t _1618_t2;
    int64_t _1618_t3;
    int64_t _1619_z;
    int64_t* _1618_t7;
    struct struct3 _1619_y;
    int64_t _1618_$retval;
    _1618_t0 = _1620_get_array;
    _1618_t2 = 15;
    _1618_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1618_t0(_1618_t2, _1618_t3);
    $line_idx--;
    _1619_z = 64;
    _1618_t7 = &_1619_z;
    _1619_y = (struct struct3) {_1619_z, _1618_t7};
    _1618_$retval = _1619_y._0;
    return _1618_$retval;
}

struct struct2 _1620_get_array(int64_t _1620_a, int64_t _1620_b){
    struct struct2 _1620_$retval;
    _1620_$retval = (struct struct2) {_1620_a, _1620_b, _1620_a, _1620_b};
    return _1620_$retval;
}


int main(void) {
  printf("%ld",_1618_main());
  return 0;
}

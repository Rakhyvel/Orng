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
int64_t _1591_main(void);
struct struct2 _1593_get_array(int64_t _1593_a, int64_t _1593_b);


/* Function definitions */
int64_t _1591_main(void){
    function0 _1591_t0;
    int64_t _1591_t2;
    int64_t _1591_t3;
    int64_t _1592_z;
    int64_t* _1591_t7;
    struct struct3 _1592_y;
    int64_t _1591_$retval;
    _1591_t0 = _1593_get_array;
    _1591_t2 = 15;
    _1591_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1591_t0(_1591_t2, _1591_t3);
    $line_idx--;
    _1592_z = 64;
    _1591_t7 = &_1592_z;
    _1592_y = (struct struct3) {_1592_z, _1591_t7};
    _1591_$retval = _1592_y._0;
    return _1591_$retval;
}

struct struct2 _1593_get_array(int64_t _1593_a, int64_t _1593_b){
    struct struct2 _1593_$retval;
    _1593_$retval = (struct struct2) {_1593_a, _1593_b, _1593_a, _1593_b};
    return _1593_$retval;
}


int main(void) {
  printf("%ld",_1591_main());
  return 0;
}

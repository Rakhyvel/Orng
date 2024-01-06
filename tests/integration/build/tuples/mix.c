/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;
struct struct2;
struct struct3;

/* Typedefs */
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
int64_t _1519_main(void);
struct struct2 _1521_get_array(int64_t _1521_a, int64_t _1521_b);

/* Function definitions */
int64_t _1519_main(void){
    function0 _1519_t0;
    int64_t _1519_t2;
    int64_t _1519_t3;
    int64_t _1520_z;
    int64_t* _1519_t7;
    struct struct3 _1520_y;
    int64_t _1519_$retval;
    _1519_t0 = _1521_get_array;
    _1519_t2 = 15;
    _1519_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1519_t0(_1519_t2, _1519_t3);
    $line_idx--;
    _1520_z = 64;
    _1519_t7 = &_1520_z;
    _1520_y = (struct struct3) {_1520_z, _1519_t7};
    _1519_$retval = _1520_y._0;
    return _1519_$retval;
}

struct struct2 _1521_get_array(int64_t _1521_a, int64_t _1521_b){
    struct struct2 _1521_$retval;
    _1521_$retval = (struct struct2) {_1521_a, _1521_b, _1521_a, _1521_b};
    return _1521_$retval;
}

int main(void) {
  printf("%ld",_1519_main());
  return 0;
}

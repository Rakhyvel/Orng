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
int64_t _1529_main(void);
struct struct2 _1531_get_array(int64_t _1531_a, int64_t _1531_b);

/* Function definitions */
int64_t _1529_main(void){
    function0 _1529_t0;
    int64_t _1529_t2;
    int64_t _1529_t3;
    int64_t _1530_z;
    int64_t* _1529_t7;
    struct struct3 _1530_y;
    int64_t _1529_$retval;
    _1529_t0 = _1531_get_array;
    _1529_t2 = 15;
    _1529_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1529_t0(_1529_t2, _1529_t3);
    $line_idx--;
    _1530_z = 64;
    _1529_t7 = &_1530_z;
    _1530_y = (struct struct3) {_1530_z, _1529_t7};
    _1529_$retval = _1530_y._0;
    return _1529_$retval;
}

struct struct2 _1531_get_array(int64_t _1531_a, int64_t _1531_b){
    struct struct2 _1531_$retval;
    _1531_$retval = (struct struct2) {_1531_a, _1531_b, _1531_a, _1531_b};
    return _1531_$retval;
}

int main(void) {
  printf("%ld",_1529_main());
  return 0;
}

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
int64_t _1511_main(void);
struct struct2 _1513_get_array(int64_t _1513_a, int64_t _1513_b);

/* Function definitions */
int64_t _1511_main(void){
    function0 _1511_t0;
    int64_t _1511_t2;
    int64_t _1511_t3;
    struct struct2 _1511_t1;
    int64_t _1512_z;
    int64_t* _1511_t7;
    struct struct3 _1512_y;
    int64_t _1511_$retval;
    _1511_t0 = _1513_get_array;
    _1511_t2 = 15;
    _1511_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1511_t1 = _1511_t0(_1511_t2, _1511_t3);
    $line_idx--;
    (void)_1511_t1;
    _1512_z = 64;
    _1511_t7 = &_1512_z;
    _1512_y = (struct struct3) {_1512_z, _1511_t7};
    _1511_$retval = _1512_y._0;
    return _1511_$retval;
}

struct struct2 _1513_get_array(int64_t _1513_a, int64_t _1513_b){
    struct struct2 _1513_$retval;
    _1513_$retval = (struct struct2) {_1513_a, _1513_b, _1513_a, _1513_b};
    return _1513_$retval;
}

int main(void) {
  printf("%ld",_1511_main());
  return 0;
}

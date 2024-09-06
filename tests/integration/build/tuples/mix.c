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
int64_t _1823_main(void);
struct struct2 _1825_get_array(int64_t _1825_a, int64_t _1825_b);


/* Function definitions */
int64_t _1823_main(void){
    function0 _1823_t0;
    int64_t _1823_t2;
    int64_t _1823_t3;
    int64_t _1824_z;
    int64_t* _1823_t9;
    struct struct3 _1824_y;
    int64_t _1823_$retval;
    _1823_t0 = (function0) _1825_get_array;
    _1823_t2 = 15;
    _1823_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1823_t0(_1823_t2, _1823_t3);
    $line_idx--;
    _1824_z = 64;
    _1823_t9 = &_1824_z;
    _1824_y = (struct struct3) {_1824_z, _1823_t9};
    _1823_$retval = _1824_y._0;
    return _1823_$retval;
}

struct struct2 _1825_get_array(int64_t _1825_a, int64_t _1825_b){
    struct struct2 _1825_$retval;
    _1825_$retval = (struct struct2) {_1825_a, _1825_b, _1825_a, _1825_b};
    return _1825_$retval;
}


int main(void) {
  printf("%ld",_1823_main());
  return 0;
}

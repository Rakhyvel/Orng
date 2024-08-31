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
int64_t _1758_main(void);
struct struct2 _1760_get_array(int64_t _1760_a, int64_t _1760_b);


/* Function definitions */
int64_t _1758_main(void){
    function0 _1758_t0;
    int64_t _1758_t2;
    int64_t _1758_t3;
    int64_t _1759_z;
    int64_t* _1758_t9;
    struct struct3 _1759_y;
    int64_t _1758_$retval;
    _1758_t0 = (function0) _1760_get_array;
    _1758_t2 = 15;
    _1758_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1758_t0(_1758_t2, _1758_t3);
    $line_idx--;
    _1759_z = 64;
    _1758_t9 = &_1759_z;
    _1759_y = (struct struct3) {_1759_z, _1758_t9};
    _1758_$retval = _1759_y._0;
    return _1758_$retval;
}

struct struct2 _1760_get_array(int64_t _1760_a, int64_t _1760_b){
    struct struct2 _1760_$retval;
    _1760_$retval = (struct struct2) {_1760_a, _1760_b, _1760_a, _1760_b};
    return _1760_$retval;
}


int main(void) {
  printf("%ld",_1758_main());
  return 0;
}

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
int64_t _1848_main(void);
struct struct2 _1850_get_array(int64_t _1850_a, int64_t _1850_b);


/* Function definitions */
int64_t _1848_main(void){
    function0 _1848_t0;
    int64_t _1848_t2;
    int64_t _1848_t3;
    int64_t _1849_z;
    int64_t* _1848_t9;
    struct struct3 _1849_y;
    int64_t _1848_$retval;
    _1848_t0 = (function0) _1850_get_array;
    _1848_t2 = 15;
    _1848_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1848_t0(_1848_t2, _1848_t3);
    $line_idx--;
    _1849_z = 64;
    _1848_t9 = &_1849_z;
    _1849_y = (struct struct3) {_1849_z, _1848_t9};
    _1848_$retval = _1849_y._0;
    return _1848_$retval;
}

struct struct2 _1850_get_array(int64_t _1850_a, int64_t _1850_b){
    struct struct2 _1850_$retval;
    _1850_$retval = (struct struct2) {_1850_a, _1850_b, _1850_a, _1850_b};
    return _1850_$retval;
}


int main(void) {
  printf("%ld",_1848_main());
  return 0;
}

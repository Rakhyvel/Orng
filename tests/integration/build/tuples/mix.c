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
int64_t _1514_main(void);
struct struct2 _1516_get_array(int64_t _1516_a, int64_t _1516_b);

/* Function definitions */
int64_t _1514_main(void){
    function0 _1514_t0;
    int64_t _1514_t2;
    int64_t _1514_t3;
    int64_t _1515_z;
    int64_t* _1514_t7;
    struct struct3 _1515_y;
    int64_t _1514_$retval;
    _1514_t0 = _1516_get_array;
    _1514_t2 = 15;
    _1514_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1514_t0(_1514_t2, _1514_t3);
    $line_idx--;
    _1515_z = 64;
    _1514_t7 = &_1515_z;
    _1515_y = (struct struct3) {_1515_z, _1514_t7};
    _1514_$retval = _1515_y._0;
    return _1514_$retval;
}

struct struct2 _1516_get_array(int64_t _1516_a, int64_t _1516_b){
    struct struct2 _1516_$retval;
    _1516_$retval = (struct struct2) {_1516_a, _1516_b, _1516_a, _1516_b};
    return _1516_$retval;
}

int main(void) {
  printf("%ld",_1514_main());
  return 0;
}

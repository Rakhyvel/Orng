/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct2;

typedef struct2(*function0)(int64_t, int64_t);

typedef struct {
    int64_t _0;
    int64_t* _1;
} struct3;

/* Function forward definitions */
int64_t _1485_main(void);
struct2 _1491_get_array(int64_t _1491_a,int64_t _1491_b);

/* Function definitions */
int64_t _1485_main(void){
    function0 _1485_t0;
    int64_t _1485_t2;
    int64_t _1485_t3;
    struct2 _1485_t1;
    int64_t _1486_z;
    int64_t* _1485_t7;
    struct3 _1486_y;
    int64_t _1485_$retval;
    _1485_t0 = _1491_get_array;
    _1485_t2 = 15;
    _1485_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1485_t1 = _1485_t0(_1485_t2, _1485_t3);
    $line_idx--;
    (void)_1485_t1;
    _1486_z = 64;
    _1485_t7 = &_1486_z;
    _1486_y = (struct3) {_1486_z, _1485_t7};
    _1485_$retval = _1486_y._0;
    return _1485_$retval;
}

struct2 _1491_get_array(int64_t _1491_a,int64_t _1491_b){
    struct2 _1491_$retval;
    _1491_$retval = (struct2) {_1491_a, _1491_b, _1491_a, _1491_b};
    return _1491_$retval;
}

int main(void) {
  printf("%ld",_1485_main());
  return 0;
}

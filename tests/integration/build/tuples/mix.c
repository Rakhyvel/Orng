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
int64_t _1556_main(void);
struct2 _1562_get_array(int64_t _1562_a,int64_t _1562_b);

/* Function definitions */
int64_t _1556_main(void){
    function0 _1556_t0;
    int64_t _1556_t2;
    int64_t _1556_t3;
    struct2 _1556_t1;
    int64_t _1557_z;
    int64_t* _1556_t7;
    struct3 _1557_y;
    int64_t _1556_$retval;
    _1556_t0 = _1562_get_array;
    _1556_t2 = 15;
    _1556_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1556_t1 = _1556_t0(_1556_t2, _1556_t3);
    $line_idx--;
    (void)_1556_t1;
    _1557_z = 64;
    _1556_t7 = &_1557_z;
    _1557_y = (struct3) {_1557_z, _1556_t7};
    _1556_$retval = _1557_y._0;
    return _1556_$retval;
}

struct2 _1562_get_array(int64_t _1562_a,int64_t _1562_b){
    struct2 _1562_$retval;
    _1562_$retval = (struct2) {_1562_a, _1562_b, _1562_a, _1562_b};
    return _1562_$retval;
}

int main(void) {
  printf("%ld",_1556_main());
  return 0;
}

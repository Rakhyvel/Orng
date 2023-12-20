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
    int64_t _2;
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _8_main(void);

/* Function definitions */
int64_t _8_main(void){
    int64_t _8_t1;
    int64_t _8_t2;
    int64_t _8_t3;
    int64_t _8_t4;
    struct0 _9_x;
    int64_t _8_t5;
    int64_t _8_t6;
    int64_t* _9_y;
    int64_t _8_t9;
    int64_t _8_t10;
    int64_t _8_$retval;
    _8_t1 = 1;
    _8_t2 = 2;
    _8_t3 = 3;
    _8_t4 = 4;
    _9_x = (struct0) {_8_t1, _8_t2, _8_t3, _8_t4};
    _8_t5 = 0;
    _8_t6 = 4;
    $bounds_check(_8_t5, _8_t6, "tests/integration/arrays/addr-index.orng:4:24:\n    let y: &mut Int = &mut x[0]\n                      ^");
    _9_y = ((int64_t*)&_9_x + _8_t5);
    *_9_y = 63;
    _8_t9 = 0;
    _8_t10 = 4;
    $bounds_check(_8_t9, _8_t10, "tests/integration/arrays/addr-index.orng:2:3:\nfn main() -> Int {\n ^");
    _8_$retval = *((int64_t*)&_9_x + _8_t9);
    return _8_$retval;
}

int main(void) {
  printf("%ld",_8_main());
  return 0;
}

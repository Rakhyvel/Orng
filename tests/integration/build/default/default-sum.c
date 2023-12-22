/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
    };
} struct0;

/* Function forward definitions */
int64_t _542_main(void);

/* Function definitions */
int64_t _542_main(void){
    int64_t _542_t0;
    struct0 _543_x;
    uint64_t _542_t3;
    int64_t _542_t4;
    uint8_t _542_t6;
    int64_t _542_t2;
    int64_t _542_$retval;
    _542_t0 = 0;
    _543_x = (struct0) {.tag=0, ._0=_542_t0};
    _542_t3 = 0;
    _542_t4 = 0;
    $tag_check(_542_t3, 0, "tests/integration/default/default-sum.orng:3:10:\n    let x: (a: Int | b | c)\n        ^");
    _542_t6 = _543_x._0 == _542_t4;
    if (_542_t6) {
        goto BB674;
    } else {
        goto BB678;
    }
BB674:
    _542_t2 = 133;
    goto BB677;
BB678:
    _542_t2 = 0;
    goto BB677;
BB677:
    _542_$retval = _542_t2;
    return _542_$retval;
}

int main(void) {
  printf("%ld",_542_main());
  return 0;
}

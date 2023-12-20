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
        uint32_t _0;
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _562_main(void);

/* Function definitions */
int64_t _562_main(void){
    int64_t _562_t0;
    struct0 _563_x;
    uint64_t _562_t2;
    int64_t _562_$retval;
    _562_t0 = 117;
    _563_x = (struct0) {.tag=1, ._1=_562_t0};
    _562_t2 = 1;
    $tag_check(_562_t2, 1, "tests/integration/errors/error.orng:2:3:\nfn main() -> Int {\n ^");
    _562_$retval = _563_x._1;
    return _562_$retval;
}

int main(void) {
  printf("%ld",_562_main());
  return 0;
}

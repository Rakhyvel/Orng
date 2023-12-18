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
int64_t _674_main(void);

/* Function definitions */
int64_t _674_main(void){
    int64_t _674_t0;
    struct0 _675_x;
    uint64_t _674_t2;
    int64_t _674_$retval;
    _674_t0 = 117;
    _675_x = (struct0) {.tag=1, ._1=_674_t0};
    _674_t2 = 1;
    $tag_check(_674_t2, 1, "tests/integration/errors/error.orng:2:3:\nfn main() -> Int {\n ^");
    _674_$retval = _675_x._1;
    return _674_$retval;
}

int main(void) {
  printf("%ld",_674_main());
  return 0;
}

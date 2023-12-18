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
        double _1;
    };
} struct0;

/* Function forward definitions */
int64_t _582_main(void);

/* Function definitions */
int64_t _582_main(void){
    int64_t _582_t0;
    struct0 _583_x;
    uint64_t _582_t2;
    int64_t _582_$retval;
    _582_t0 = 139;
    _583_x = (struct0) {.tag=0, ._0=_582_t0};
    _582_t2 = 0;
    $tag_check(_582_t2, 0, "tests/integration/default/default-error.orng:2:3:\nfn main() -> Int {\n ^");
    _582_$retval = _583_x._0;
    return _582_$retval;
}

int main(void) {
  printf("%ld",_582_main());
  return 0;
}

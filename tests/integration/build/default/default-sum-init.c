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
int64_t _640_main(void);

/* Function definitions */
int64_t _640_main(void){
    int64_t _640_t0;
    struct0 _641_x;
    uint64_t _640_t2;
    int64_t _640_$retval;
    _640_t0 = 134;
    _641_x = (struct0) {.tag=0, ._0=_640_t0};
    _640_t2 = 0;
    $tag_check(_640_t2, 0, "tests/integration/default/default-sum-init.orng:2:3:\nfn main() -> Int {\n ^");
    _640_$retval = _641_x._0;
    return _640_$retval;
}

int main(void) {
  printf("%ld",_640_main());
  return 0;
}

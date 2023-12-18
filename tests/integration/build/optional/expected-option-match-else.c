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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1231_main(void);

/* Function definitions */
int64_t _1231_main(void){
    int64_t _1231_t10;
    struct0 _1232_x;
    uint64_t _1231_t12;
    int64_t _1231_$retval;
    _1231_t10 = 128;
    _1232_x = (struct0) {.tag=1, ._1=_1231_t10};
    _1231_t12 = 1;
    $tag_check(_1231_t12, 1, "tests/integration/optional/expected-option-match-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1231_$retval = _1232_x._1;
    return _1231_$retval;
}

int main(void) {
  printf("%ld",_1231_main());
  return 0;
}

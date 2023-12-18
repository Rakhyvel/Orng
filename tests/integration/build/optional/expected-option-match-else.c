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
int64_t _1228_main(void);

/* Function definitions */
int64_t _1228_main(void){
    int64_t _1228_t10;
    struct0 _1229_x;
    uint64_t _1228_t12;
    int64_t _1228_$retval;
    _1228_t10 = 128;
    _1229_x = (struct0) {.tag=1, ._1=_1228_t10};
    _1228_t12 = 1;
    $tag_check(_1228_t12, 1, "tests/integration/optional/expected-option-match-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1228_$retval = _1229_x._1;
    return _1228_$retval;
}

int main(void) {
  printf("%ld",_1228_main());
  return 0;
}

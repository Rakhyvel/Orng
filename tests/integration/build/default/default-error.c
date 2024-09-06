/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    uint64_t tag;
    union {
        double _0;
    };
};

struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
        struct struct1 _1;
    };
};

/* Function forward definitions */
int64_t _528_main(void);


/* Function definitions */
int64_t _528_main(void){
    int64_t _528_t0;
    struct struct0 _529_x;
    uint64_t _528_t3;
    int64_t _528_$retval;
    _528_t0 = 139;
    _529_x = (struct struct0) {.tag=0, ._0=_528_t0};
    _528_t3 = 0;
    $tag_check(_528_t3, 0, "tests/integration/default/default-error.orng:2:8:\nfn main() -> Int {\n      ^");
    _528_$retval = _529_x._0;
    return _528_$retval;
}


int main(void) {
  printf("%ld",_528_main());
  return 0;
}

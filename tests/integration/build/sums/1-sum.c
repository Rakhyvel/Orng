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
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _1377_main(void);
struct1 _1379_get_the_sum(void);

/* Function definitions */
int64_t _1377_main(void){
    function0 _1377_t0;
    struct1 _1377_t1;
    struct1 _1378_a;
    uint64_t _1377_t2;
    int64_t _1377_$retval;
    _1377_t0 = _1379_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _1377_t1 = _1377_t0();
    $line_idx--;
    _1378_a = _1377_t1;
    _1377_t2 = _1377_t1.tag;
    $tag_check(_1377_t2, 0, "tests/integration/sums/1-sum.orng:4:3:\nfn main() -> Int {\n ^");
    _1377_$retval = _1378_a._0;
    return _1377_$retval;
}

struct1 _1379_get_the_sum(void){
    int64_t _1379_t0;
    struct1 _1379_$retval;
    _1379_t0 = 235;
    _1379_$retval = (struct1) {.tag=0, ._0=_1379_t0};
    return _1379_$retval;
}

int main(void) {
  printf("%ld",_1377_main());
  return 0;
}

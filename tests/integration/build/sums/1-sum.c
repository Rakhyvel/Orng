/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1489_main(void);
struct struct1 _1491_get_the_sum(void);


/* Function definitions */
int64_t _1489_main(void){
    function0 _1489_t0;
    struct struct1 _1489_t1;
    struct struct1 _1490_a;
    uint64_t _1489_t3;
    int64_t _1489_$retval;
    _1489_t0 = (function0) _1491_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _1489_t1 = _1489_t0();
    $line_idx--;
    _1490_a = _1489_t1;
    _1489_t3 = _1489_t1.tag;
    $tag_check(_1489_t3, 0, "tests/integration/sums/1-sum.orng:4:8:\nfn main() -> Int {\n      ^");
    _1489_$retval = _1490_a._0;
    return _1489_$retval;
}

struct struct1 _1491_get_the_sum(void){
    int64_t _1491_t0;
    struct struct1 _1491_$retval;
    _1491_t0 = 235;
    _1491_$retval = (struct struct1) {.tag=0, ._0=_1491_t0};
    return _1491_$retval;
}


int main(void) {
  printf("%ld",_1489_main());
  return 0;
}

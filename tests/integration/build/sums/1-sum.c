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
int64_t _1502_main(void);
struct struct1 _1504_get_the_sum(void);


/* Function definitions */
int64_t _1502_main(void){
    function0 _1502_t0;
    struct struct1 _1502_t1;
    struct struct1 _1503_a;
    uint64_t _1502_t3;
    int64_t _1502_$retval;
    _1502_t0 = (function0) _1504_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _1502_t1 = _1502_t0();
    $line_idx--;
    _1503_a = _1502_t1;
    _1502_t3 = _1502_t1.tag;
    $tag_check(_1502_t3, 0, "tests/integration/sums/1-sum.orng:4:8:\nfn main() -> Int {\n      ^");
    _1502_$retval = _1503_a._0;
    return _1502_$retval;
}

struct struct1 _1504_get_the_sum(void){
    int64_t _1504_t0;
    struct struct1 _1504_$retval;
    _1504_t0 = 235;
    _1504_$retval = (struct struct1) {.tag=0, ._0=_1504_t0};
    return _1504_$retval;
}


int main(void) {
  printf("%ld",_1502_main());
  return 0;
}

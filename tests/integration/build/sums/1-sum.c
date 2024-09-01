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
int64_t _1478_main(void);
struct struct1 _1480_get_the_sum(void);


/* Function definitions */
int64_t _1478_main(void){
    function0 _1478_t0;
    struct struct1 _1478_t1;
    struct struct1 _1479_a;
    uint64_t _1478_t3;
    int64_t _1478_$retval;
    _1478_t0 = (function0) _1480_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _1478_t1 = _1478_t0();
    $line_idx--;
    _1479_a = _1478_t1;
    _1478_t3 = _1478_t1.tag;
    $tag_check(_1478_t3, 0, "tests/integration/sums/1-sum.orng:4:3:\nfn main() -> Int {\n ^");
    _1478_$retval = _1479_a._0;
    return _1478_$retval;
}

struct struct1 _1480_get_the_sum(void){
    int64_t _1480_t0;
    struct struct1 _1480_$retval;
    _1480_t0 = 235;
    _1480_$retval = (struct struct1) {.tag=0, ._0=_1480_t0};
    return _1480_$retval;
}


int main(void) {
  printf("%ld",_1478_main());
  return 0;
}

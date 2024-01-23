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
int64_t _1424_main(void);
struct struct1 _1426_get_the_sum(void);


/* Function definitions */
int64_t _1424_main(void){
    function0 _1424_t0;
    struct struct1 _1424_t1;
    struct struct1 _1425_a;
    uint64_t _1424_t2;
    int64_t _1424_$retval;
    _1424_t0 = _1426_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _1424_t1 = _1424_t0();
    $line_idx--;
    _1425_a = _1424_t1;
    _1424_t2 = _1424_t1.tag;
    $tag_check(_1424_t2, 0, "tests/integration/sums/1-sum.orng:4:3:\nfn main() -> Int {\n ^");
    _1424_$retval = _1425_a._0;
    return _1424_$retval;
}

struct struct1 _1426_get_the_sum(void){
    int64_t _1426_t0;
    struct struct1 _1426_$retval;
    _1426_t0 = 235;
    _1426_$retval = (struct struct1) {.tag=0, ._0=_1426_t0};
    return _1426_$retval;
}


int main(void) {
  printf("%ld",_1424_main());
  return 0;
}

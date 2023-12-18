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
int64_t _1620_main(void);
struct1 _1622_get_the_sum(void);

/* Function definitions */
int64_t _1620_main(void){
    function0 _1620_t0;
    struct1 _1620_t1;
    struct1 _1621_a;
    uint64_t _1620_t2;
    int64_t _1620_$retval;
    _1620_t0 = _1622_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _1620_t1 = _1620_t0();
    $line_idx--;
    _1621_a = _1620_t1;
    _1620_t2 = _1620_t1.tag;
    $tag_check(_1620_t2, 0, "tests/integration/sums/1-sum.orng:4:3:\nfn main() -> Int {\n ^");
    _1620_$retval = _1621_a._0;
    return _1620_$retval;
}

struct1 _1622_get_the_sum(void){
    int64_t _1622_t0;
    struct1 _1622_$retval;
    _1622_t0 = 235;
    _1622_$retval = (struct1) {.tag=0, ._0=_1622_t0};
    return _1622_$retval;
}

int main(void) {
  printf("%ld",_1620_main());
  return 0;
}

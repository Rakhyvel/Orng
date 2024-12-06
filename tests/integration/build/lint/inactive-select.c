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
        int64_t _1;
    };
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1127_main(void);
struct struct1 _1129_f(void);


/* Function definitions */
int64_t _1127_main(void){
    function0 _1127_t0;
    struct struct1 _1127_t1;
    struct struct1 _1128_x;
    uint64_t _1127_t3;
    int64_t _1127_$retval;
    _1127_t0 = (function0) _1129_f;
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _1127_t1 = _1127_t0();
    $line_idx--;
    _1128_x = _1127_t1;
    _1127_t3 = _1127_t1.tag;
    $tag_check(_1127_t3, 1, "tests/integration/lint/inactive-select.orng:2:8:\nfn main() -> Int {\n      ^");
    _1127_$retval = _1128_x._1;
    return _1127_$retval;
}

struct struct1 _1129_f(void){
    int64_t _1129_t0;
    struct struct1 _1129_$retval;
    _1129_t0 = 4;
    _1129_$retval = (struct struct1) {.tag=0, ._0=_1129_t0};
    return _1129_$retval;
}


int main(void) {
  printf("%ld",_1127_main());
  return 0;
}

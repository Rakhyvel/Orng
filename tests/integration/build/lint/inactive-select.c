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
int64_t _1113_main(void);
struct struct1 _1115_f(void);


/* Function definitions */
int64_t _1113_main(void){
    function0 _1113_t0;
    struct struct1 _1113_t1;
    struct struct1 _1114_x;
    uint64_t _1113_t3;
    int64_t _1113_$retval;
    _1113_t0 = (function0) _1115_f;
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _1113_t1 = _1113_t0();
    $line_idx--;
    _1114_x = _1113_t1;
    _1113_t3 = _1113_t1.tag;
    $tag_check(_1113_t3, 1, "tests/integration/lint/inactive-select.orng:2:8:\nfn main() -> Int {\n      ^");
    _1113_$retval = _1114_x._1;
    return _1113_$retval;
}

struct struct1 _1115_f(void){
    int64_t _1115_t0;
    struct struct1 _1115_$retval;
    _1115_t0 = 4;
    _1115_$retval = (struct struct1) {.tag=0, ._0=_1115_t0};
    return _1115_$retval;
}


int main(void) {
  printf("%ld",_1113_main());
  return 0;
}

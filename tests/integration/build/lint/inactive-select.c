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
int64_t _1056_main(void);
struct struct1 _1058_f(void);


/* Function definitions */
int64_t _1056_main(void){
    function0 _1056_t0;
    struct struct1 _1056_t1;
    struct struct1 _1057_x;
    uint64_t _1056_t2;
    int64_t _1056_$retval;
    _1056_t0 = _1058_f;
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _1056_t1 = _1056_t0();
    $line_idx--;
    _1057_x = _1056_t1;
    _1056_t2 = _1056_t1.tag;
    $tag_check(_1056_t2, 1, "tests/integration/lint/inactive-select.orng:2:3:\nfn main() -> Int {\n ^");
    _1056_$retval = _1057_x._1;
    return _1056_$retval;
}

struct struct1 _1058_f(void){
    int64_t _1058_t0;
    struct struct1 _1058_$retval;
    _1058_t0 = 4;
    _1058_$retval = (struct struct1) {.tag=0, ._0=_1058_t0};
    return _1058_$retval;
}


int main(void) {
  printf("%ld",_1056_main());
  return 0;
}

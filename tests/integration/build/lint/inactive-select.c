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
int64_t _1155_main(void);
struct struct1 _1157_f(void);


/* Function definitions */
int64_t _1155_main(void){
    function0 _1155_t0;
    struct struct1 _1155_t1;
    struct struct1 _1156_x;
    uint64_t _1155_t3;
    int64_t _1155_$retval;
    _1155_t0 = (function0) _1157_f;
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _1155_t1 = _1155_t0();
    $line_idx--;
    _1156_x = _1155_t1;
    _1155_t3 = _1155_t1.tag;
    $tag_check(_1155_t3, 1, "tests/integration/lint/inactive-select.orng:2:8:\nfn main() -> Int {\n      ^");
    _1155_$retval = _1156_x._1;
    return _1155_$retval;
}

struct struct1 _1157_f(void){
    int64_t _1157_t0;
    struct struct1 _1157_$retval;
    _1157_t0 = 4;
    _1157_$retval = (struct struct1) {.tag=0, ._0=_1157_t0};
    return _1157_$retval;
}


int main(void) {
  printf("%ld",_1155_main());
  return 0;
}

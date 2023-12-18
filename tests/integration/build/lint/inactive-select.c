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
        int64_t _1;
    };
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _1165_main(void);
struct1 _1167_f(void);

/* Function definitions */
int64_t _1165_main(void){
    function0 _1165_t0;
    struct1 _1165_t1;
    struct1 _1166_x;
    uint64_t _1165_t2;
    int64_t _1165_$retval;
    _1165_t0 = _1167_f;
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _1165_t1 = _1165_t0();
    $line_idx--;
    _1166_x = _1165_t1;
    _1165_t2 = _1165_t1.tag;
    $tag_check(_1165_t2, 1, "tests/integration/lint/inactive-select.orng:2:3:\nfn main() -> Int {\n ^");
    _1165_$retval = _1166_x._1;
    return _1165_$retval;
}

struct1 _1167_f(void){
    int64_t _1167_t0;
    struct1 _1167_$retval;
    _1167_t0 = 4;
    _1167_$retval = (struct1) {.tag=0, ._0=_1167_t0};
    return _1167_$retval;
}

int main(void) {
  printf("%ld",_1165_main());
  return 0;
}

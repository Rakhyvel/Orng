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
int64_t _41_main(void);
struct1 _43_f(void);

/* Function definitions */
int64_t _41_main(void){
    function0 _41_t0;
    struct1 _41_t1;
    struct1 _42_x;
    uint64_t _41_t2;
    int64_t _41_$retval;
    _41_t0 = _43_f;
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _41_t1 = _41_t0();
    $line_idx--;
    _42_x = _41_t1;
    _41_t2 = _41_t1.tag;
    $tag_check(_41_t2, 1, "tests/integration/lint/inactive-select.orng:2:3:\nfn main() -> Int {\n ^");
    _41_$retval = _42_x._1;
    return _41_$retval;
}

struct1 _43_f(void){
    int64_t _43_t0;
    struct1 _43_$retval;
    _43_t0 = 4;
    _43_$retval = (struct1) {.tag=0, ._0=_43_t0};
    return _43_$retval;
}

int main(void) {
  printf("%ld",_41_main());
  return 0;
}

/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1041_main(void);
struct struct1 _1043_f(void);

/* Function definitions */
int64_t _1041_main(void){
    function0 _1041_t0;
    struct struct1 _1041_t1;
    struct struct1 _1042_x;
    uint64_t _1041_t2;
    int64_t _1041_$retval;
    _1041_t0 = _1043_f;
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _1041_t1 = _1041_t0();
    $line_idx--;
    _1042_x = _1041_t1;
    _1041_t2 = _1041_t1.tag;
    $tag_check(_1041_t2, 1, "tests/integration/lint/inactive-select.orng:2:3:\nfn main() -> Int {\n ^");
    _1041_$retval = _1042_x._1;
    return _1041_$retval;
}

struct struct1 _1043_f(void){
    int64_t _1043_t0;
    struct struct1 _1043_$retval;
    _1043_t0 = 4;
    _1043_$retval = (struct struct1) {.tag=0, ._0=_1043_t0};
    return _1043_$retval;
}

int main(void) {
  printf("%ld",_1041_main());
  return 0;
}

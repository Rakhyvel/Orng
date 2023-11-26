/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _6_add(int64_t _6_x,int64_t _6_y);
int64_t _2_main(void);

/* Function definitions */
int64_t _6_add(int64_t _6_x,int64_t _6_y) {
    int64_t _6_$retval;
    _6_$retval = $add_int64_t(_6_x, _6_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _6_$retval;
}

int64_t _2_main(void) {
    int64_t _2_$retval;
    _2_$retval = 235;
    return _2_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}

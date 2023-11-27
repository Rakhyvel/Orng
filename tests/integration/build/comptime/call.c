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
int64_t _89_add(int64_t _89_x,int64_t _89_y);
int64_t _85_main(void);

/* Function definitions */
int64_t _89_add(int64_t _89_x,int64_t _89_y) {
    int64_t _89_$retval;
    _89_$retval = $add_int64_t(_89_x, _89_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _89_$retval;
}

int64_t _85_main(void) {
    int64_t _85_$retval;
    _85_$retval = 235;
    return _85_$retval;
}

int main(void) {
  printf("%ld",_85_main());
  return 0;
}

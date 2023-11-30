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
int64_t _850_main(void);
int64_t _852_add(int64_t _852_x,int64_t _852_y);

/* Function definitions */
int64_t _850_main(void) {
    function0 _850_t0;
    int64_t _850_t2;
    int64_t _850_t3;
    int64_t _850_t1;
    int64_t _850_$retval;
    _850_t0 = _852_add;
    _850_t2 = 40;
    _850_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _850_t1 = _850_t0(_850_t2, _850_t3);
    $line_idx--;
    _850_$retval = _850_t1;
    return _850_$retval;
}

int64_t _852_add(int64_t _852_x,int64_t _852_y) {
    int64_t _852_$retval;
    _852_$retval = $add_int64_t(_852_x, _852_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _852_$retval;
}

int main(void) {
  printf("%ld",_850_main());
  return 0;
}

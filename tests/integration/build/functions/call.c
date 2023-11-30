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
int64_t _827_main(void);
int64_t _829_add(int64_t _829_x,int64_t _829_y);

/* Function definitions */
int64_t _827_main(void) {
    function0 _827_t0;
    int64_t _827_t2;
    int64_t _827_t3;
    int64_t _827_t1;
    int64_t _827_$retval;
    _827_t0 = _829_add;
    _827_t2 = 40;
    _827_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _827_t1 = _827_t0(_827_t2, _827_t3);
    $line_idx--;
    _827_$retval = _827_t1;
    return _827_$retval;
}

int64_t _829_add(int64_t _829_x,int64_t _829_y) {
    int64_t _829_$retval;
    _829_$retval = $add_int64_t(_829_x, _829_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _829_$retval;
}

int main(void) {
  printf("%ld",_827_main());
  return 0;
}

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
int64_t _593_main(void);
int64_t _595_add(int64_t _595_x,int64_t _595_y);

/* Function definitions */
int64_t _593_main(void) {
    function0 _593_t0;
    int64_t _593_t2;
    int64_t _593_t3;
    int64_t _593_t1;
    int64_t _593_$retval;
    _593_t0 = _595_add;
    _593_t2 = 40;
    _593_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _593_t1 = _593_t0(_593_t2, _593_t3);
    $line_idx--;
    _593_$retval = _593_t1;
    return _593_$retval;
}

int64_t _595_add(int64_t _595_x,int64_t _595_y) {
    int64_t _595_$retval;
    _595_$retval = $add_int64_t(_595_x, _595_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _595_$retval;
}

int main(void) {
  printf("%ld",_593_main());
  return 0;
}

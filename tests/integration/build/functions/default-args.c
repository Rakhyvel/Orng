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

typedef int64_t(*function0)(    int64_t,     int64_t);

/* Function forward definitions */
int64_t _26_main(void);
int64_t _28_add(int64_t _28_x,int64_t _28_y);

/* Function definitions */
int64_t _26_main(void) {
    function0 _26_t0;
    function0 _26_t2;
    int64_t _26_t4;
    int64_t _26_t5;
    int64_t _26_t3;
    function0 _26_t6;
    int64_t _26_t8;
    int64_t _26_t9;
    int64_t _26_t7;
    int64_t _26_t1;
    int64_t _26_$retval;
    _26_t0 = _28_add;
    _26_t2 = _28_add;
    _26_t4 = 47;
    _26_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _26_t3 = _26_t2(_26_t4, _26_t5);
    $line_idx--;
    _26_t6 = _28_add;
    _26_t8 = 1;
    _26_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _26_t7 = _26_t6(_26_t8, _26_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _26_t1 = _26_t0(_26_t3, _26_t7);
    $line_idx--;
    _26_$retval = _26_t1;
    return _26_$retval;
}

int64_t _28_add(int64_t _28_x,int64_t _28_y) {
    int64_t _28_$retval;
    _28_$retval = $add_int64_t(_28_x, _28_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _28_$retval;
}

int main(void) {
  printf("%ld",_26_main());
  return 0;
}

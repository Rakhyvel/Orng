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
int64_t _705_main(void);
int64_t _707_add(int64_t _707_x,int64_t _707_y);

/* Function definitions */
int64_t _705_main(void) {
    function0 _705_t0;
    function0 _705_t2;
    int64_t _705_t4;
    int64_t _705_t5;
    int64_t _705_t3;
    function0 _705_t6;
    int64_t _705_t8;
    int64_t _705_t9;
    int64_t _705_t7;
    int64_t _705_t1;
    int64_t _705_$retval;
    _705_t0 = _707_add;
    _705_t2 = _707_add;
    _705_t4 = 47;
    _705_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _705_t3 = _705_t2(_705_t4, _705_t5);
    $line_idx--;
    _705_t6 = _707_add;
    _705_t8 = 1;
    _705_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _705_t7 = _705_t6(_705_t8, _705_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _705_t1 = _705_t0(_705_t3, _705_t7);
    $line_idx--;
    _705_$retval = _705_t1;
    return _705_$retval;
}

int64_t _707_add(int64_t _707_x,int64_t _707_y) {
    int64_t _707_$retval;
    _707_$retval = $add_int64_t(_707_x, _707_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _707_$retval;
}

int main(void) {
  printf("%ld",_705_main());
  return 0;
}

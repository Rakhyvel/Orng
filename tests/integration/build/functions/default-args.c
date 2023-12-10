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
int64_t _697_main(void);
int64_t _699_add(int64_t _699_x,int64_t _699_y);

/* Function definitions */
int64_t _697_main(void) {
    function0 _697_t0;
    function0 _697_t2;
    int64_t _697_t4;
    int64_t _697_t5;
    int64_t _697_t3;
    function0 _697_t6;
    int64_t _697_t8;
    int64_t _697_t9;
    int64_t _697_t7;
    int64_t _697_t1;
    int64_t _697_$retval;
    _697_t0 = _699_add;
    _697_t2 = _699_add;
    _697_t4 = 47;
    _697_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _697_t3 = _697_t2(_697_t4, _697_t5);
    $line_idx--;
    _697_t6 = _699_add;
    _697_t8 = 1;
    _697_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _697_t7 = _697_t6(_697_t8, _697_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _697_t1 = _697_t0(_697_t3, _697_t7);
    $line_idx--;
    _697_$retval = _697_t1;
    return _697_$retval;
}

int64_t _699_add(int64_t _699_x,int64_t _699_y) {
    int64_t _699_$retval;
    _699_$retval = $add_int64_t(_699_x, _699_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _699_$retval;
}

int main(void) {
  printf("%ld",_697_main());
  return 0;
}

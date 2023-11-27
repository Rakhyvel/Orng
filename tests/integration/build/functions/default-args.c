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
int64_t _641_main(void);
int64_t _643_add(int64_t _643_x,int64_t _643_y);

/* Function definitions */
int64_t _641_main(void) {
    function0 _641_t0;
    function0 _641_t2;
    int64_t _641_t4;
    int64_t _641_t5;
    int64_t _641_t3;
    function0 _641_t6;
    int64_t _641_t8;
    int64_t _641_t9;
    int64_t _641_t7;
    int64_t _641_t1;
    int64_t _641_$retval;
    _641_t0 = _643_add;
    _641_t2 = _643_add;
    _641_t4 = 47;
    _641_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _641_t3 = _641_t2(_641_t4, _641_t5);
    $line_idx--;
    _641_t6 = _643_add;
    _641_t8 = 1;
    _641_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _641_t7 = _641_t6(_641_t8, _641_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _641_t1 = _641_t0(_641_t3, _641_t7);
    $line_idx--;
    _641_$retval = _641_t1;
    return _641_$retval;
}

int64_t _643_add(int64_t _643_x,int64_t _643_y) {
    int64_t _643_$retval;
    _643_$retval = $add_int64_t(_643_x, _643_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _643_$retval;
}

int main(void) {
  printf("%ld",_641_main());
  return 0;
}

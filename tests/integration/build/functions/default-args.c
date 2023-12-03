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
int64_t _673_main(void);
int64_t _675_add(int64_t _675_x,int64_t _675_y);

/* Function definitions */
int64_t _673_main(void) {
    function0 _673_t0;
    function0 _673_t2;
    int64_t _673_t4;
    int64_t _673_t5;
    int64_t _673_t3;
    function0 _673_t6;
    int64_t _673_t8;
    int64_t _673_t9;
    int64_t _673_t7;
    int64_t _673_t1;
    int64_t _673_$retval;
    _673_t0 = _675_add;
    _673_t2 = _675_add;
    _673_t4 = 47;
    _673_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _673_t3 = _673_t2(_673_t4, _673_t5);
    $line_idx--;
    _673_t6 = _675_add;
    _673_t8 = 1;
    _673_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _673_t7 = _673_t6(_673_t8, _673_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _673_t1 = _673_t0(_673_t3, _673_t7);
    $line_idx--;
    _673_$retval = _673_t1;
    return _673_$retval;
}

int64_t _675_add(int64_t _675_x,int64_t _675_y) {
    int64_t _675_$retval;
    _675_$retval = $add_int64_t(_675_x, _675_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _675_$retval;
}

int main(void) {
  printf("%ld",_673_main());
  return 0;
}

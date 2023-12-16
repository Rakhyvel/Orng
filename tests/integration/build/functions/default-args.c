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
int64_t _902_main(void);
int64_t _904_add(int64_t _904_x,int64_t _904_y);

/* Function definitions */
int64_t _902_main(void){
    function0 _902_t0;
    function0 _902_t2;
    int64_t _902_t4;
    int64_t _902_t5;
    int64_t _902_t3;
    function0 _902_t6;
    int64_t _902_t8;
    int64_t _902_t9;
    int64_t _902_t7;
    int64_t _902_t1;
    int64_t _902_$retval;
    _902_t0 = _904_add;
    _902_t2 = _904_add;
    _902_t4 = 47;
    _902_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _902_t3 = _902_t2(_902_t4, _902_t5);
    $line_idx--;
    _902_t6 = _904_add;
    _902_t8 = 1;
    _902_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _902_t7 = _902_t6(_902_t8, _902_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _902_t1 = _902_t0(_902_t3, _902_t7);
    $line_idx--;
    _902_$retval = _902_t1;
    return _902_$retval;
}

int64_t _904_add(int64_t _904_x,int64_t _904_y){
    int64_t _904_$retval;
    _904_$retval = $add_int64_t(_904_x, _904_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _904_$retval;
}

int main(void) {
  printf("%ld",_902_main());
  return 0;
}

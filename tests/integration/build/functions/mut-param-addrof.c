/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct2;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    int64_t* _0;
    int64_t _1;
};

typedef void(*function1)(int64_t*, int64_t);

/* Function forward definitions */
int64_t _996_main(void);
int64_t _998_sum_down(int64_t _998_x);
void _1003_inc(int64_t* _1003_x, int64_t _1003_i);


/* Function definitions */
int64_t _996_main(void){
    function0 _996_t0;
    int64_t _996_t2;
    int64_t _996_t1;
    int64_t _996_t3;
    int64_t _996_$retval;
    _996_t0 = (function0) _998_sum_down;
    _996_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _996_t1 = _996_t0(_996_t2);
    $line_idx--;
    _996_t3 = 2;
    _996_$retval = $add_int64_t(_996_t1, _996_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _996_$retval;
}

int64_t _998_sum_down(int64_t _998_x){
    int64_t _1000_i;
    int64_t _998_t2;
    uint8_t _998_t3;
    function1 _998_t4;
    int64_t* _998_t6;
    int64_t _998_t7;
    int64_t _998_$retval;
    _1000_i = _998_x;
    goto BB1188;
BB1188:
    _998_t2 = 0;
    _998_t3 = _1000_i>=_998_t2;
    if (_998_t3) {
        goto BB1189;
    } else {
        goto BB1194;
    }
BB1189:
    _998_t4 = (function1) _1003_inc;
    _998_t6 = &_998_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _998_t4(_998_t6, _1000_i);
    $line_idx--;
    _998_t7 = 1;
    _1000_i = $sub_int64_t(_1000_i, _998_t7, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1188;
BB1194:
    _998_$retval = _998_x;
    return _998_$retval;
}

void _1003_inc(int64_t* _1003_x, int64_t _1003_i){
    *_1003_x = $add_int64_t(*_1003_x, _1003_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}


int main(void) {
  printf("%ld",_996_main());
  return 0;
}

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
int64_t _998_main(void);
int64_t _1000_sum_down(int64_t _1000_x);
void _1005_inc(int64_t* _1005_x, int64_t _1005_i);


/* Function definitions */
int64_t _998_main(void){
    function0 _998_t0;
    int64_t _998_t2;
    int64_t _998_t1;
    int64_t _998_t3;
    int64_t _998_$retval;
    _998_t0 = (function0) _1000_sum_down;
    _998_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _998_t1 = _998_t0(_998_t2);
    $line_idx--;
    _998_t3 = 2;
    _998_$retval = $add_int64_t(_998_t1, _998_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _998_$retval;
}

int64_t _1000_sum_down(int64_t _1000_x){
    int64_t _1002_i;
    int64_t _1000_t2;
    uint8_t _1000_t3;
    function1 _1000_t4;
    int64_t* _1000_t6;
    int64_t _1000_t7;
    int64_t _1000_$retval;
    _1002_i = _1000_x;
    goto BB1175;
BB1175:
    _1000_t2 = 0;
    _1000_t3 = _1002_i>=_1000_t2;
    if (_1000_t3) {
        goto BB1176;
    } else {
        goto BB1181;
    }
BB1176:
    _1000_t4 = (function1) _1005_inc;
    _1000_t6 = &_1000_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _1000_t4(_1000_t6, _1002_i);
    $line_idx--;
    _1000_t7 = 1;
    _1002_i = $sub_int64_t(_1002_i, _1000_t7, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1175;
BB1181:
    _1000_$retval = _1000_x;
    return _1000_$retval;
}

void _1005_inc(int64_t* _1005_x, int64_t _1005_i){
    *_1005_x = $add_int64_t(*_1005_x, _1005_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}


int main(void) {
  printf("%ld",_998_main());
  return 0;
}

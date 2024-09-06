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
int64_t _970_main(void);
int64_t _972_sum_down(int64_t _972_x);
void _977_inc(int64_t* _977_x, int64_t _977_i);


/* Function definitions */
int64_t _970_main(void){
    function0 _970_t0;
    int64_t _970_t2;
    int64_t _970_t1;
    int64_t _970_t3;
    int64_t _970_$retval;
    _970_t0 = (function0) _972_sum_down;
    _970_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _970_t1 = _970_t0(_970_t2);
    $line_idx--;
    _970_t3 = 2;
    _970_$retval = $add_int64_t(_970_t1, _970_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _970_$retval;
}

int64_t _972_sum_down(int64_t _972_x){
    int64_t _974_i;
    int64_t _972_t2;
    uint8_t _972_t3;
    function1 _972_t4;
    int64_t* _972_t6;
    int64_t _972_t7;
    int64_t _972_$retval;
    _974_i = _972_x;
    goto BB1141;
BB1141:
    _972_t2 = 0;
    _972_t3 = _974_i>=_972_t2;
    if (_972_t3) {
        goto BB1142;
    } else {
        goto BB1147;
    }
BB1142:
    _972_t4 = (function1) _977_inc;
    _972_t6 = &_972_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _972_t4(_972_t6, _974_i);
    $line_idx--;
    _972_t7 = 1;
    _974_i = $sub_int64_t(_974_i, _972_t7, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1141;
BB1147:
    _972_$retval = _972_x;
    return _972_$retval;
}

void _977_inc(int64_t* _977_x, int64_t _977_i){
    *_977_x = $add_int64_t(*_977_x, _977_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}


int main(void) {
  printf("%ld",_970_main());
  return 0;
}

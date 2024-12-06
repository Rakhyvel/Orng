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
int64_t _968_main(void);
int64_t _970_sum_down(int64_t _970_x);
void _975_inc(int64_t* _975_x, int64_t _975_i);


/* Function definitions */
int64_t _968_main(void){
    function0 _968_t0;
    int64_t _968_t2;
    int64_t _968_t1;
    int64_t _968_t3;
    int64_t _968_$retval;
    _968_t0 = (function0) _970_sum_down;
    _968_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _968_t1 = _968_t0(_968_t2);
    $line_idx--;
    _968_t3 = 2;
    _968_$retval = $add_int64_t(_968_t1, _968_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _968_$retval;
}

int64_t _970_sum_down(int64_t _970_x){
    int64_t _972_i;
    int64_t _970_t2;
    uint8_t _970_t3;
    function1 _970_t4;
    int64_t* _970_t6;
    int64_t _970_t7;
    int64_t _970_$retval;
    _972_i = _970_x;
    goto BB1144;
BB1144:
    _970_t2 = 0;
    _970_t3 = _972_i>=_970_t2;
    if (_970_t3) {
        goto BB1145;
    } else {
        goto BB1150;
    }
BB1145:
    _970_t4 = (function1) _975_inc;
    _970_t6 = &_970_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _970_t4(_970_t6, _972_i);
    $line_idx--;
    _970_t7 = 1;
    _972_i = $sub_int64_t(_972_i, _970_t7, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1144;
BB1150:
    _970_$retval = _970_x;
    return _970_$retval;
}

void _975_inc(int64_t* _975_x, int64_t _975_i){
    *_975_x = $add_int64_t(*_975_x, _975_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}


int main(void) {
  printf("%ld",_968_main());
  return 0;
}

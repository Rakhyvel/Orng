/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct5;

/* Struct, union, and function definitions */
struct struct2 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct2* _0;
    struct struct2 _1;
};

typedef struct struct2(*function0)(struct struct2*, struct struct2);

typedef int64_t(*function3)(struct struct2*);

struct struct5 {
    struct struct2* _0;
    struct struct2 _1;
};

typedef struct struct2(*function4)(struct struct2*, struct struct2);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _109_main(void);
struct struct2 _105_add(void* _105_$self_ptr, struct struct2 _105_other);
int64_t _107_cab(void* _107_$self_ptr);

/* Trait vtable implementations */

/* Function definitions */
int64_t _109_main(void){
    int64_t _109_t1;
    int64_t _109_t2;
    struct struct2 _110_a;
    struct struct2* _109_t4;
    int64_t _109_t6;
    int64_t _109_t7;
    struct struct2 _109_t5;
    function4 _109_t8;
    struct struct2 _109_t3;
    struct struct2* _109_t10;
    function3 _109_t11;
    int64_t _109_t9;
    int64_t _109_$retval;
    _109_t1 = 100;
    _109_t2 = 90;
    _110_a = (struct struct2) {_109_t1, _109_t2};
    _109_t4 = &_110_a;
    _109_t6 = 100;
    _109_t7 = 9;
    _109_t5 = (struct struct2) {_109_t6, _109_t7};
    _109_t8 = (function4) _105_add;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:13:12:\n    a = a.>add((100, 9))\n          ^";
    _109_t3 = _109_t8(_109_t4, _109_t5);
    $line_idx--;
    _110_a = _109_t3;
    _109_t10 = &_109_t3;
    _109_t11 = (function3) _107_cab;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:14:8:\n    a.>cab()\n      ^";
    _109_t9 = _109_t11(_109_t10);
    $line_idx--;
    _109_$retval = _109_t9;
    return _109_$retval;
}

struct struct2 _105_add(void* _105_$self_ptr, struct struct2 _105_other){
    struct struct2 _106_self;
    int64_t _105_t1;
    int64_t _105_t2;
    struct struct2 _105_$retval;
    _106_self = *(struct struct2*)_105_$self_ptr;
    _105_t1 = $add_int64_t(_106_self._0, _105_other._0, "tests/integration/traits/self-impl.orng:5:18:\n        (self.x + other.x, self.y + other.y)\n                ^");
    _105_t2 = $add_int64_t(_106_self._1, _105_other._1, "tests/integration/traits/self-impl.orng:5:36:\n        (self.x + other.x, self.y + other.y)\n                                  ^");
    _105_$retval = (struct struct2) {_105_t1, _105_t2};
    return _105_$retval;
}

int64_t _107_cab(void* _107_$self_ptr){
    struct struct2 _108_self;
    int64_t _107_$retval;
    _108_self = *(struct struct2*)_107_$self_ptr;
    _107_$retval = $add_int64_t(_108_self._0, _108_self._1, "tests/integration/traits/self-impl.orng:8:35:\n    fn cab(self) -> Int { self.x + self.y }\n                                 ^");
    return _107_$retval;
}


int main(void) {
  printf("%ld",_109_main());
  return 0;
}

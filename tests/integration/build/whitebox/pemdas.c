/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1269_main(void);

/* Function definitions */
int64_t _1269_main(void) {
    int64_t _1270_x;
    int64_t* _1270_y;
    int64_t _1269_t3;
    uint8_t _1269_t5;
    int64_t _1269_t2;
    int64_t _1269_$retval;
    int64_t _1272_z;
    int64_t* _1269_t7;
    int64_t _1269_t10;
    int64_t _1269_t11;
    int64_t _1269_t13;
    int64_t _1269_t14;
    int64_t _1269_t17;
    _1270_x = 0;
    _1270_y = &_1270_x;
    _1269_t3 = 0;
    _1269_t5 = *_1270_y == _1269_t3;
    if (_1269_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1272_z = *_1270_y;
    _1269_t7 = &_1272_z;
    *_1269_t7 = $add_int64_t(_1272_z, _1272_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1272_z = $sub_int64_t(_1272_z, _1272_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1272_z = $mult_int64_t(_1272_z, _1272_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1269_t10 = 1;
    _1269_t11 = $add_int64_t(_1272_z, _1269_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1272_z = $div_int64_t(_1272_z, _1269_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1269_t13 = 1;
    _1269_t14 = $add_int64_t(_1272_z, _1269_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1272_z = $mod_int64_t(_1272_z, _1269_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1269_t17 = -1;
    _1272_z = $mult_int64_t(_1272_z, _1269_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1269_t2 = $mult_int64_t(_1272_z, _1269_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB6;
BB7:
    _1269_t2 = 1000;
    goto BB6;
BB6:
    _1269_$retval = _1269_t2;
    return _1269_$retval;
}

int main(void) {
  printf("%ld",_1269_main());
  return 0;
}

/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1168_main(void);

/* Function definitions */
int64_t _1168_main(void) {
    int64_t _1169_x;
    int64_t* _1169_y;
    int64_t _1168_t3;
    uint8_t _1168_t5;
    uint8_t _1168_t4;
    int64_t _1171_z;
    int64_t* _1168_t7;
    int64_t _1168_t10;
    int64_t _1168_t11;
    int64_t _1168_t13;
    int64_t _1168_t14;
    int64_t _1168_t17;
    int64_t _1168_t2;
    int64_t _1168_$retval;
    _1169_x = 0;
    _1169_y = &_1169_x;
    _1168_t3 = 0;
    _1168_t5 = *_1169_y == _1168_t3;
    if (_1168_t5) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _1168_t4 = 1;
    goto BB2;
BB9:
    _1168_t4 = 0;
    goto BB2;
BB2:
    if (_1168_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1171_z = *_1169_y;
    _1168_t7 = &_1171_z;
    *_1168_t7 = $add_int64_t(_1171_z, _1171_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1171_z = $sub_int64_t(_1171_z, _1171_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1171_z = $mult_int64_t(_1171_z, _1171_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1168_t10 = 1;
    _1168_t11 = $add_int64_t(_1171_z, _1168_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1171_z = $div_int64_t(_1171_z, _1168_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1168_t13 = 1;
    _1168_t14 = $add_int64_t(_1171_z, _1168_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1171_z = $mod_int64_t(_1171_z, _1168_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1168_t17 = -1;
    _1171_z = $mult_int64_t(_1171_z, _1168_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1168_t2 = $mult_int64_t(_1171_z, _1168_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB6;
BB7:
    _1168_t2 = 1000;
    goto BB6;
BB6:
    _1168_$retval = _1168_t2;
    return _1168_$retval;
}

int main(void) {
  printf("%ld",_1168_main());
  return 0;
}

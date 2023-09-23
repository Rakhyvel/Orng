/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _3_x;
    int64_t* _3_y;
    int64_t _5_z;
    int64_t* _2_t8;
    int64_t _2_t2;
    int64_t _2_$retval;
    _3_x = 0;
    _3_y = &_3_x;
    if (*_3_y) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _2_t2 = 1000;
    goto BB4;
BB1:
    _5_z = *_3_y;
    _2_t8 = _3_y;
    **&_2_t8 = _5_z + _5_z;
    _5_z = _5_z - _5_z;
    _5_z = _5_z * _5_z;
    _5_z = _5_z / (_5_z + 1);
    _5_z = _5_z % (_5_z + 1);
    _5_z = powf(_5_z, (_5_z + 1));
    _2_t2 = _5_z * -1.0e+00;
BB4:
    _2_$retval = _2_t2;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}

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
    uint8_t _3_found;
    int64_t _4_n;
    int64_t _2_$retval;
    int64_t _2_t13;
    _3_found = 0;
    _4_n = 0;
BB1:
    if (_4_n < 10) {
        goto BB2;
    } else {
        goto BB14;
    }
BB2:
    if (_3_found) {
        goto BB3;
    } else {
        goto BB5;
    }
BB14:
    if (_3_found) {
        goto BB15;
    } else {
        goto BB19;
    }
BB3:
    _4_n = 100;
BB5:
    if (_4_n == 6) {
        goto BB6;
    } else {
        goto BB10;
    }
BB15:
    _2_t13 = 15;
    goto BB18;
BB19:
    _2_t13 = 4;
    goto BB18;
BB6:
    _3_found = 1;
BB10:
    _4_n = _4_n + 1;
    goto BB1;
BB18:
    _2_$retval = _2_t13;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}

// debug utilities made use by the Orng compiler when in debug mode
// © 2023 Joseph Shimel. All rights reserved.

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

inline static int8_t $negate_int8_t(const int8_t x, const char *restrict line) {
    if (x == -0x80) {
        $lines[$line_idx++] = line;
        $panic("negation overflow");
    }
    return -x;
}

inline static int16_t $negate_int16_t(const int16_t x, const char *restrict line) {
    if (x == -0x8000) {
        $lines[$line_idx++] = line;
        $panic("negation overflow");
    }
    return -x;
}

inline static int32_t $negate_int32_t(const int32_t x, const char *restrict line) {
    if (x == -0x80000000) {
        $lines[$line_idx++] = line;
        $panic("negation overflow");
    }
    return -x;
}

inline static int64_t $negate_int64_t(const int64_t x, const char *restrict line) {
    if (x == -0x8000000000000000) {
        $lines[$line_idx++] = line;
        $panic("negation overflow");
    }
    return -x;
}

inline static int8_t $add_int8_t(const int8_t lhs, const int8_t rhs, const char *restrict line) {
    if (lhs >= 0) {
        if (0x7F - lhs < rhs) {
            $lines[$line_idx++] = line;
            $panic("addition overflow");
        }
    } else {
        if (rhs < (-0x80) - lhs) {
            $lines[$line_idx++] = line;
            $panic("addition overflow");
        }
    }
    return lhs + rhs;
}

inline static int16_t $add_int16_t(const int16_t lhs, const int16_t rhs, const char *restrict line) {
    if (lhs >= 0) {
        if (0x7FFF - lhs < rhs) {
            $lines[$line_idx++] = line;
            $panic("addition overflow");
        }
    } else {
        if (rhs < (-0x8000) - lhs) {
            $lines[$line_idx++] = line;
            $panic("addition overflow");
        }
    }
    return lhs + rhs;
}

inline static int32_t $add_int32_t(const int32_t lhs, const int32_t rhs, const char *restrict line) {
    if (lhs >= 0) {
        if (0x7FFFFFFF - lhs < rhs) {
            $lines[$line_idx++] = line;
            $panic("addition overflow");
        }
    } else {
        if (rhs < (-0x80000000) - lhs) {
            $lines[$line_idx++] = line;
            $panic("addition overflow");
        }
    }
    return lhs + rhs;
}

inline static int64_t $add_int64_t(const int64_t lhs, const int64_t rhs, const char *restrict line) {
    if (lhs >= 0) {
        if (0x7FFFFFFFFFFFFFFF - lhs < rhs) {
            $lines[$line_idx++] = line;
            $panic("addition overflow");
        }
    } else {
        if (rhs < (-0x8000000000000000) - lhs) {
            $lines[$line_idx++] = line;
            $panic("addition overflow");
        }
    }
    return lhs + rhs;
}
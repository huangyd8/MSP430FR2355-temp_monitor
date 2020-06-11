/*
 *
 * Table definition for character
 * offsets.  The offsets listed represent
 * the number of pixels from the right side edge
 * of the character to the edge of the 8x8 space.
 * Including the offset into draw string function allows
 * character spacing to be even with varying character
 * widths.
 *
 * NOTE:  I don't think the values listed below are correct
 *
 */


#include <stdint.h>
#include <stddef.h>

#include "offset.h"

//assume first entry is char 32, or space
const uint8_t offset[] =
{
 4,      // ' '   char 32
 3,      // '!'   char 33
 2,      // '"'   char 34
 1,      // '#'   char 35
 2,      // '$'   char 36
 1,      // '%'   char 37
 1,      // '&'   char 38
 5,      // '''   char 39
 3,      // '('   char 40
 3,      // ')'   char 41
 0,      // '*'   char 42
 2,      // '+'   char 43
 4,      // ','   char 44
 2,      // '-'   char 45
 4,      // '.'   char 46
 1,      // '/'   char 47
 1,      // '0'   char 48
 2,      // '1'   char 49
 2,      // '2'   char 50
 2,      // '3'   char 51
 1,      // '4'   char 52
 2,      // '5'   char 53
 2,      // '6'   char 54
 2,      // '7'   char 55
 2,      // '8'   char 56
 2,      // '9'   char 57
 4,      // ':'   char 58
 4,      // ';'   char 59
 3,      // '<'   char 60
 2,      // '='   char 61
 2,      // '>'   char 62
 2,      // '?'   char 63
 1,      // '@'   char 64
 2,      // 'A'   char 65
 1,      // 'B'   char 66
 1,      // 'C'   char 67
 1,      // 'D'   char 68
 1,      // 'E'   char 69
 1,      // 'F'   char 70
 1,      // 'G'   char 71
 2,      // 'H'   char 72
 3,      // 'I'   char 73
 1,      // 'J'   char 74
 1,      // 'K'   char 75
 1,      // 'L'   char 76
 1,      // 'M'   char 77
 1,      // 'N'   char 78
 1,      // 'O'   char 79
 1,      // 'P'   char 80
 2,      // 'Q'   char 81
 1,      // 'R'   char 82
 2,      // 'S'   char 83
 2,      // 'T'   char 84
 2,      // 'U'   char 85
 2,      // 'V'   char 86
 1,      // 'W'   char 87
 1,      // 'X'   char 88
 2,      // 'Y'   char 89
 1,      // 'Z'   char 90
 3,      // '['   char 91
 1,      // backslash   char 92
 3,      // ']'   char 93
 1,      // '^'   char 94
 0,      // '_'   char 95
 3,      // '`'   char 96
 1,      // 'a'   char 97
 1,      // 'b'   char 98
 2,      // 'c'   char 99
 1,      // 'd'   char 100
 2,      // 'e'   char 101
 2,      // 'f'   char 102
 1,      // 'g'   char 103
 1,      // 'h'   char 104
 3,      // 'i'   char 105
 2,      // 'j'   char 106
 1,      // 'k'   char 107
 3,      // 'l'   char 108
 1,      // 'm'   char 109
 2,      // 'n'   char 110
 2,      // 'o'   char 111
 1,      // 'p'   char 112
 1,      // 'q'   char 113
 1,      // 'r'   char 114
 2,      // 's'   char 115
 2,      // 't'   char 116
 1,      // 'u'   char 117
 2,      // 'v'   char 118
 1,      // 'w'   char 119
 1,      // 'x'   char 120
 2,      // 'y'   char 121
 2,      // 'z'   char 122
 2,      // '{'   char 123
 3,      // '|'   char 124
 2,      // '}'   char 125
 1,      // '~'   char 126
 1,      // ' '   char 127
 1,      // ' '   char 128
 1,      // ' '   char 129
 1,      // ' '   char 130
 1,      // ' '   char 131
 1,      // ' '   char 132
 1,      // ' '   char 133
 1,      // ' '   char 134
 1,      // ' '   char 135
 1,      // ' '   char 136
 1,      // ' '   char 137
 1,      // ' '   char 138
 1,      // ' '   char 139
 1,      // ' '   char 140
 1,      // ' '   char 141
 1,      // ' '   char 142
 1,      // ' '   char 143
 1,      // ' '   char 144
 1,      // ' '   char 145
 1,      // ' '   char 146
 1,      // ' '   char 147
 1,      // ' '   char 148
 1,      // ' '   char 149
 1,      // ' '   char 150
 1,      // ' '   char 151
 1,      // ' '   char 152
 1,      // ' '   char 153
 1,      // ' '   char 154
 1,      // ' '   char 155
 1,      // ' '   char 156
 1,      // ' '   char 157
 1,      // ' '   char 158
 1,      // ' '   char 159
 1,      // ' '   char 160
 1,      // ' '   char 161
 1,      // ' '   char 162
 1,      // ' '   char 163
 1,      // ' '   char 164
 1,      // ' '   char 165
 1,      // ' '   char 166
 1,      // ' '   char 167
 1,      // ' '   char 168
 1,      // ' '   char 169
 1,      // ' '   char 170
 1,      // ' '   char 171
 1,      // ' '   char 172
 1,      // ' '   char 173
 1,      // ' '   char 174
 1,      // ' '   char 175
 4,      // '°'  char 176
 3,      // '±'  char 177
};

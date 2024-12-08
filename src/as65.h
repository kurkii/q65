#include <stdint.h>

#ifndef AS65_H
#define AS65_H

typedef struct as65_line {
    char *opcode;
    char *operand1;
    char *operand2;
} as65_line;

typedef struct as65_instruction_info {
    char *str;
    /* Opcodes for the different addressing modes, 0 if specific addressing is unavailable. */
    uint8_t immediate;
    uint8_t zeropage;
    uint8_t zeropageX;
    uint8_t absolute;
    uint8_t absoluteX;
    uint8_t absoluteY;
    uint8_t indirectX;
    uint8_t indirectY;
    uint8_t relative;
    uint8_t accumulator;
    uint8_t implied;
    uint8_t indirect;
    uint8_t zeropageY;
} as65_instruction_info;

#define MAX_LINE_LENGTH     4096
#define INSTRUCTION_COUNT   55

static as65_instruction_info operand_array[] = {
    {"adc", 0x69, 0x65, 0x75, 0x6D, 0x7D, 0x79, 0x61, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"and", 0x29, 0x25, 0x35, 0x2D, 0x3D, 0x39, 0x21, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"asl", 0x00, 0x06, 0x16, 0x0E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00},
    {"bcc", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00},
    {"bcs", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x00, 0x00, 0x00},
    {"beq", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00},
    {"bit", 0x00, 0x24, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"bmi", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00},
    {"bne", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0x00},
    {"bpl", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00},
    {"brk", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00},
    {"bvc", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00},
    {"bvs", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00},
    {"clc", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00},
    {"cld", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x00},
    {"cli", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00},
    {"clv", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x00, 0x00},
    {"cmp", 0xC9, 0xC5, 0xD5, 0xCD, 0xDD, 0xD9, 0xC1, 0xD1, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"cpx", 0xE0, 0xE4, 0x00, 0xEC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"cpy", 0xC0, 0xC4, 0x00, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"dec", 0x00, 0xC6, 0xD6, 0xCE, 0xDE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"dex", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCA, 0x00, 0x00},
    {"dey", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00},
    {"eor", 0x49, 0x45, 0x55, 0x4D, 0x5D, 0x59, 0x41, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"inc", 0x00, 0xE6, 0xF6, 0xEE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"inx", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x00, 0x00},
    {"iny", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00},
    {"jmp", 0x00, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x00},
    {"jsr", 0x00, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"lda", 0xA9, 0xA5, 0xB5, 0xAD, 0xBD, 0xB9, 0xA1, 0xB1, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"ldx", 0xA2, 0xA6, 0x00, 0xAE, 0x00, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB6},
    {"ldy", 0xA0, 0xA4, 0xB4, 0xAC, 0xBC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"lsr", 0x00, 0x46, 0x56, 0x4E, 0x5E, 0x00, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x00},
    {"nop", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEA, 0x00, 0x00},
    {"ora", 0x09, 0x05, 0x15, 0x0D, 0x1D, 0x19, 0x01, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"pha", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00},
    {"php", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00},
    {"pla", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00},
    {"plp", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00},
    {"rol", 0x00, 0x26, 0x36, 0x2E, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00},
    {"ror", 0x00, 0x66, 0x76, 0x6E, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x6A, 0x00, 0x00, 0x00},
    {"rti", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00},
    {"rts", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00},
    {"sbc", 0xE9, 0xE5, 0xF5, 0xED, 0xFD, 0xF9, 0xE1, 0xF1, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"sec", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00},
    {"sed", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00},
    {"sei", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00},
    {"sta", 0x00, 0x85, 0x95, 0x8D, 0x9D, 0x99, 0x81, 0x91, 0x00, 0x00, 0x00, 0x00, 0x00},
    {"stx", 0x00, 0x86, 0x00, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96},
    {"sty", 0x00, 0x84, 0x00, 0x8C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94},
    {"tax", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0x00, 0x00},
    {"tay", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00},
    {"tsx", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xBA, 0x00, 0x00},
    {"txa", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8A, 0x00, 0x00},
    {"txs", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9A, 0x00, 0x00},
    {"tya", 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x00, 0x00},
};

enum {
    LOG_INFO = 0,
    LOG_WARN,
    LOG_ERROR
};

void as65_log(int err, char* msg);

as65_line parse_line(char *buffer);

int check_instruction(char *opcode, char *operand1, char *operand2);


#endif


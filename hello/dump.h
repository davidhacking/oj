#ifndef DUMP_H_
#define DUMP_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DMSG(...) \
    do { \
        printf(__VA_ARGS__); \
    } while(0)

static void __unused dump_data(const char *data, size_t size, const char *msg)
{
    /* 3 chars for each byte, 32 bytes a line. */
    static const size_t BYTES_PER_BYTE = 3;
    static const size_t BYTES_PER_LINE = 32;

    char line[BYTES_PER_BYTE * BYTES_PER_LINE + 1];
    size_t i = 0;
    size_t done = 0;

    DMSG("%s\n", msg);
    while (done < size) {
        for (i = 0;
            i < ((size - done < BYTES_PER_LINE) ? size - done : BYTES_PER_LINE);
            ++i) {
            snprintf(line + BYTES_PER_BYTE * i, BYTES_PER_BYTE + 1, "%02hhx ", data[done + i]);
        }
        line[BYTES_PER_BYTE * i] = 0;
        DMSG("%s\n", line);
        done += i;
    }
    DMSG("==========================\n");
}

static char hex(uint8_t a)
{
	if (a >= 10)
		return 'A' + (a - 10);
	else
		return '0' + a;
}

static void __unused dump_data_4_java(const char *data, size_t size, const char *msg)
{
	size_t i = 0;
	char *buf = NULL;
	char *out = NULL;
	char *origin_buf = NULL;
	uint32_t delta = 12;

	buf = (char *) malloc(size * delta + 1);
	out = buf;
	origin_buf = buf;
	if (!buf) {
		DMSG("TEE_Malloc fail");
		goto terminal;
	}

	DMSG("%s\n", msg);
	while (i < size) {
		snprintf(buf, delta + 1, "(byte)0x%02x, ", data[i++]);
		buf += delta;
		if (i % 8 == 0) {
			DMSG("%s\n", out);
			out = buf;
		}
	}
	DMSG("%s\n", out);
	DMSG("==========================\n");
terminal:
	free(origin_buf);
	return;
}

static void hexdump(uint8_t *buf, uint32_t len)
{
	uint32_t i;
	char tmp[3 * 8 + 10];
	char *p = NULL;
	uint8_t *pbuf = buf;

	if (len == 0) {
		DMSG("NULL");
		return;
	}

	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < len; i++) {
		if (i % 8 == 0)
			p = tmp;
		*p++ = hex(*pbuf / 16);
		*p++ = hex(*pbuf % 16);
		pbuf++;
		*p++ = ':';
		if (i % 8 == 7)
			DMSG("%s", tmp);
	}

	if (i % 8 != 0) {
		*p = 0;
		DMSG("%s", tmp);
	}
}

#endif

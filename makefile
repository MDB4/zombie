# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = gcc                        # compiler to use

LINKERFLAG = -lm

SRCS := $(wildcard *.c)
BINS := ~/.local/bin/$(SRCS:%.c=%)

all: ${BINS}

%: %.o
	@echo "Checking.."
	${CC} ${LINKERFLAG} $< -o ~/.local/bin/$@

%.o: %.c
	@echo "Creating object.."
	${CC} -c ~/.local/bin/$<

clean:
	@echo "Cleaning up..."
	rm -rvf *.o ~/.local/bin/${BINS}

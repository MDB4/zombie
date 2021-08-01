# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects
DESTDIR = ~/.local

.PHONY = all install uninstall clean

CC = gcc                        # compiler to use

LINKERFLAG = -lm

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}

%: %.o
	@echo "Checking.."
	${CC} ${LINKERFLAG} $< -o $@

%.o: %.c
	@echo "Creating object.."
	${CC} -c $<

install:
	mkdir -p $(DESTDIR)/bin
	cp $@ $(DESTDIR)/bin/${BINS}

uninstall:
	rm -f $(DESTDIR)/bin/${BINS}

clean:
	@echo "Cleaning up..."
	rm -rvf *.o ${BINS}

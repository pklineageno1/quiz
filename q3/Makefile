CC ?= gcc
CFLAGS_common ?= -O3 -Wall -std=gnu99
PERF_FLAGS = stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,cs,branch-misses,instructions,cycles 

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run: $(EXEC)
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf $(PERF_FLAGS) ./iterative

run_re: $(EXEC)
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf  $(PERF_FLAGS) ./recursive

clean:
	$(RM) $(EXEC) *.o perf.*

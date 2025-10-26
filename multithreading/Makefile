# Compiler and flags (-pthread ensures proper linking with the POSIX threads library)
CC = gcc
CFLAGS = -pthread

# Executable targets
STATIC_SLEEP_EXE = sleep_static.x
DYNAMIC_SLEEP_EXE = sleep_dynamic.x

STATIC_RET_VALUE_EXE = ret_value_static.x
DYNAMIC_RET_VALUE_EXE = ret_value_dynamic.x

# Source files
SRC_SLEEP = sleep.c
SRC_RET_VALUE = ret_value.c

# Option to build all static executables at once
all_static: $(STATIC_SLEEP_EXE) $(STATIC_RET_VALUE_EXE)

# Option to build all dynamic executables at once
all_dynamic: $(DYNAMIC_SLEEP_EXE) $(DYNAMIC_RET_VALUE_EXE)

# Static linkink with pthreads library
# -static forces static linking in main_static
$(STATIC_SLEEP_EXE): $(SRC_SLEEP)
	$(CC) $(CFLAGS) -static -o $(STATIC_SLEEP_EXE) $(SRC_SLEEP) -lpthread

$(STATIC_RET_VALUE_EXE): $(SRC_RET_VALUE)
	$(CC) $(CFLAGS) -static -o $(STATIC_RET_VALUE_EXE) $(SRC_RET_VALUE) -lpthread

# Dynamic linking with pthreads library (default)
# the default main_dynamic links dynamically with libpthread.so
$(DYNAMIC_SLEEP_EXE): $(SRC_SLEEP)
	$(CC) $(CFLAGS) -o $(DYNAMIC_SLEEP_EXE) $(SRC_SLEEP) -lpthread

$(DYNAMIC_RET_VALUE_EXE): $(SRC_RET_VALUE)
	$(CC) $(CFLAGS) -o $(DYNAMIC_RET_VALUE_EXE) $(SRC_RET_VALUE) -lpthread

clean:
	rm -f *.x

# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug_win32
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug_win32)
  ASCII_TicTacToe_config = debug_win32
endif
ifeq ($(config),debug_win64)
  ASCII_TicTacToe_config = debug_win64
endif
ifeq ($(config),release_win32)
  ASCII_TicTacToe_config = release_win32
endif
ifeq ($(config),release_win64)
  ASCII_TicTacToe_config = release_win64
endif

PROJECTS := ASCII\ TicTacToe

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

ASCII\ TicTacToe:
ifneq (,$(ASCII_TicTacToe_config))
	@echo "==== Building ASCII TicTacToe ($(ASCII_TicTacToe_config)) ===="
	@${MAKE} --no-print-directory -C . -f ASCII\ TicTacToe.make config=$(ASCII_TicTacToe_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f ASCII\ TicTacToe.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug_win32"
	@echo "  debug_win64"
	@echo "  release_win32"
	@echo "  release_win64"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   ASCII TicTacToe"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"
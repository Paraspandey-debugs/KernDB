# Top-level Makefile that configures and builds the project using CMake
BUILD_DIR := build
CONFIG ?= Release
CMAKE := cmake

.PHONY: all configure build run clean rebuild

all: build

configure:
	@mkdir -p $(BUILD_DIR)
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(CONFIG)

build: configure
	$(CMAKE) --build $(BUILD_DIR) --config $(CONFIG) -- -j$(shell nproc)

run: build
	$(BUILD_DIR)/repl

rebuild: clean all

clean:
	rm -rf $(BUILD_DIR)

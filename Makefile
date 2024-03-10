CXX := gcc
CXXFLAGS := -std=c++14 -Wall -I include -I C:/SDL2-w64/include
CXXFLAGS_DEBUG := -g
CXXFLAGS_RELEASE := -DNDEBUG -O3
LDFLAGS := -L C:/SDL2-w64/lib
LDLIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image


SRC_DIR := src
DEBUG_DIR := bin/debug
RELEASE_DIR := bin/release

all: $(DEBUG_DIR)/main
release: $(RELEASE_DIR)/main

$(DEBUG_DIR) $(RELEASE_DIR):
	mkdir -p $@

define compile_and_link
$1/%.o: $$(SRC_DIR)/%.cpp | $1
	$$(CXX) $$(CXXFLAGS) $2 -c $$< -o $$@

$1/main: $$(patsubst $$(SRC_DIR)/%.cpp,$1/%.o,$$(wildcard $$(SRC_DIR)/*.cpp))
	$$(CXX) $$(LDFLAGS) $$^ $$(LDLIBS) -o $$@
endef

$(eval $(call compile_and_link,$(DEBUG_DIR),$(CXXFLAGS_DEBUG)))
$(eval $(call compile_and_link,$(RELEASE_DIR),$(CXXFLAGS_RELEASE)))

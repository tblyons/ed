BIN_NAME = ed
SRC_PATH = src
SOURCES = src/main.cpp \
          src/IO/InputStream.cpp \
          src/IO/OutputStream.cpp \
          src/IO/Screen.cpp \
          src/IO/Terminal.cpp
INCLUDES = 
CXX=clang++
CXXFLAGS = -g -std=c++14 -stdlib=libc++ -Weverything -pedantic -Wno-c++98-compat
LDFLAGS = -g -stdlib=libc++ -lc++abi
OBJECTS = $(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)
DEPS = $(OBJECTS:.o=.d)
BUILD_PATH = build/debug

#Main rule
all: dirs $(BUILD_PATH)/$(BIN_NAME)
	@$(RM) $(BIN_NAME)
	@ln -s $(BUILD_PATH)/$(BIN_NAME) $(BIN_NAME)

.PHONY: dirs
dirs:
	@mkdir -p $(dir $(OBJECTS))

$(BUILD_PATH)/$(BIN_NAME): $(OBJECTS)
	@printf "\nLinking $@\n"
	@$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@printf "\nCompiling $<\n"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(BIN_NAME)
	$(RM) -r build

-include $(DEPS)


CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := 
CC_FLAGS := -std=c++11

main.bin: $(OBJ_FILES)
	g++ $(LD_FLAGS) $^ -o $@

obj/%.o: %.cpp
	g++ $(CC_FLAGS) -c $< -o $@

clean:
	rm $(OBJ_FILES)

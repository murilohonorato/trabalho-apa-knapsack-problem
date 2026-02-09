CXX = g++
CXXFLAGS = -O3 -Wall
SRC_DIR = codigos
DATA_DIR = dados
TARGET = $(SRC_DIR)/exec

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/knapsack.cpp
HDRS = $(SRC_DIR)/knapsack.hpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

%: $(DATA_DIR)/input%.txt $(TARGET)
	@echo "Executando $<..."
	@./$(TARGET) < $<

clean:
	rm -f $(TARGET)

main: main.cpp
	g++ main.cpp window.cpp -o game -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
clean:
	rm -rf game

.PHONY: clean run

run: ./build/Release/smtpBot
	./build/Release/smtpBot

./build/Release/smtpBot: build ./src/*.cpp ./src/**/*.cpp ./src/**/*.hpp

	cmake --preset=conan-release
	cmake --build --preset=conan-release

build:
	conan install . --build=missing -pr=./profiles/linux-gcc20-release

clean:
	rm -rf build/ CMakeCache.txt CMakeFiles CMakeUserPresets.json

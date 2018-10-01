all: mf

mf: mf.cpp
	g++ -g -fno-stack-protector -no-pie -Wno-format-security -o mf mf.cpp

clean:
	rm mf
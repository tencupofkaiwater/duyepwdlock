all:
	g++ pwd_lock.cpp -Wall -g -O0 -o pwdlock

clean:
	rm -f pwdlock

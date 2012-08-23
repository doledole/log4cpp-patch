test:test.cpp
	g++ -o test test.cpp -I /home/dfs/third_party/log4cpp-1.1/include/ \
		/home/dfs/third_party/log4cpp-1.1/lib/liblog4cpp.a -lpthread

clean:
	rm -f test async_test.log* test.log*

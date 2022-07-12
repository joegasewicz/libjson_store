EXECUTABLE_NAME=json_store_test

clean:
	$(info '/======= Cleaning all library files =======/')
	$(RM) -rf *.o
	$(RM) -rf *.a
	$(RM) -rf lib/*.a

build:
	$(info '/======== Building library ================/')
	gcc -c json_store.c
	# Create archive from object files
	ar cr libjson_store.a json_store.o
	# list contents:
	ar t libjson_store.a
	# Move archives to include dir
	mv libjson_store.a lib

test:
	make clean
	make build
	gcc json_store_test.c -ljson_store -ljson-c -o $(EXECUTABLE_NAME) -I include -L lib
	./$(EXECUTABLE_NAME)

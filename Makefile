all:
	make -C ./src/

clean:
	make clean -C ./src
	rm -rf curves libcurves.so

conv: conv.o conv_tb.o
	clang conv.o conv_tb.o -o conv

conv_tb.o: conv_tb.cpp conv_tb.h conv.h
	clang -c conv_tb.cpp -o conv_tb.o

conv.o: conv.cpp conv.h
	clang -c conv.cpp -o conv.o

.PHONY: clean
clean:
	rm -rf conv.o conv_tb.o conv output.bin

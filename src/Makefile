#list of files for tokenizer
OBJS= tokenizermain.o tokenhistory.o ui.o
CFLAGS= -g -O3 

#target built in make
all: tokenizer
#recompile file if tokenizermain is changed
tokenizermain.o: tokenizermain.c tokenizer.h
	cc -c tokenizermain.c

#recompile file if tokenhistory is changed
tokenhistory.o: tokenhistory.c history.h
	cc -c tokenhistory.c

#recompile file if tokenhistory or tokenizermain are changed
ui.o: ui.c tokenhistory.c tokenizermain.c tokenizer.h history.h
	cc -c ui.c tokenhistory.c tokenizermain.c

#recompile if object files are changed along with executable
tokenizer: $(OBJS)
	cc -o tokenizer$(CFLAGS) $(OBJS)

#remove object files and autosaved files
clean:
	rm -f *.o *~ tokenizer
#runs the executable
run: tokenizer
	./tokenizer


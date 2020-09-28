#list of files for tokenizer
OBJS= tokenizermain.o tokenhistory.o ui.o
CFLAGS= -g -O3 

#target built in make
all: tokenizer
#recompile if object files are changed along with executable
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

#remove object files and autosaved files
clean:
	rm -f *.o *~ tokenizer
#runs the executable
run: tokenizer
	./tokenizer


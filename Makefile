CC     = gcc
CFLAGS = -Wall -O2 -Wno-unused-result -g
LIB    = -lm
OBJ    = src/main.o src/image.o src/LUT.o
RM     = rm -f
BIN    = bin/minigimp
DIRNAME = $(shell basename $$PWD)
BACKUP  = $(shell date +`basename $$PWD`-%m.%d.%H.%M.zip)
STDNAME = $(DIRNAME).zip

all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(BIN)
	@echo "--------------------------------------------------------------"
	@echo "            to execute type: ./$(BIN) "
	@echo "--------------------------------------------------------------"

src/image.o : src/image.c src/image.h
	@echo "compile image"
	$(CC) $(CFLAGS) -o src/image.o -c $<  
	@echo "done..."

src/LUT.o : src/LUT.c src/LUT.h src/image.h
	@echo "compile LUT"
	$(CC) $(CFLAGS) -o src/LUT.o -c $<  
	@echo "done..."

src/main.o : src/main.c src/image.o src/image.h src/LUT.h
	@echo "compile main"
	$(CC) $(CFLAGS) -o src/main.o -c $<  
	@echo "done..."

clean :	
	@echo "**************************"
	@echo "CLEAN"
	@echo "**************************"
	$(RM) *~ $(OBJ) $(BIN)    

bigclean :
	@echo "**************************"
	@echo "BIG CLEAN"
	@echo "**************************"
	find . -name '*~' -exec rm -fv {} \;
	$(RM) *~ $(OBJ) $(BIN)

zip : clean 
	@echo "**************************"
	@echo "ZIP"
	@echo "**************************"
	cd .. && zip -r $(BACKUP) $(DIRNAME)

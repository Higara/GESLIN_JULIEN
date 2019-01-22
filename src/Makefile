CC     = gcc
CFLAGS = -Wall -O2 -Wno-unused-result -g
LIB    = -lm
OBJ    = main.o image.o LUT.o
RM     = rm -f
BIN    = cparti
DIRNAME = $(shell basename $$PWD)
BACKUP  = $(shell date +`basename $$PWD`-%m.%d.%H.%M.zip)
STDNAME = $(DIRNAME).zip

all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(BIN)
	@echo "--------------------------------------------------------------"
	@echo "            to execute type: ./ $(BIN) "
	@echo "--------------------------------------------------------------"

image.o : image.c image.h LUT.h
	@echo "compile image"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

main.o : main.c image.o image.h LUT.h
	@echo "compile main"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

LUT.o : LUT.c LUT.h
	@echo "compile LUT"
	$(CC) $(CFLAGS) -c $<  
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

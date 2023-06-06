COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 2
LASTNAME = Vural
GITUSERID = mertcanvural
EXE = schedule_cp2

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g 
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)



$(BIN)/$(EXE): $(OBJ)/main.o $(OBJ)/StudentList.o $(OBJ)/CourseList.o $(OBJ)/Student.o $(OBJ)/Course.o $(OBJ)/CourseInfoList.o $(OBJ)/StudentInfoList.o $(OBJ)/StudentInfo.o $(OBJ)/CourseInfo.o
	$(CC) $(FLAGS) $(OBJ)/main.o $(OBJ)/StudentList.o $(OBJ)/CourseList.o $(OBJ)/Student.o $(OBJ)/Course.o $(OBJ)/CourseInfoList.o $(OBJ)/StudentInfoList.o $(OBJ)/StudentInfo.o $(OBJ)/CourseInfo.o -o $@


$(OBJ)/main.o: main.cpp StudentList.h CourseList.h Student.h Course.h CourseInfoList.h StudentInfoList.h StudentInfo.h CourseInfo.h
	$(CC) $(FLAGS) -c main.cpp -o $@

$(OBJ)/Student.o: Student.cpp Student.h CourseList.h
	$(CC) $(FLAGS) -c Student.cpp -o $@

$(OBJ)/StudentList.o: StudentList.cpp StudentList.h Student.h
	$(CC) $(FLAGS) -c StudentList.cpp -o $@

$(OBJ)/CourseList.o: CourseList.cpp CourseList.h Course.h
	$(CC) $(FLAGS) -c CourseList.cpp -o $@

$(OBJ)/Course.o: Course.cpp Course.h StudentList.h CourseInfoList.h
	$(CC) $(FLAGS) -c Course.cpp -o $@


$(OBJ)/CourseInfoList.o: CourseInfoList.cpp CourseInfoList.h CourseInfo.h
	$(CC) $(FLAGS) -c CourseInfoList.cpp -o $@

$(OBJ)/StudentInfoList.o: StudentInfoList.cpp StudentInfoList.h StudentInfo.h
	$(CC) $(FLAGS) -c StudentInfoList.cpp -o $@

$(OBJ)/StudentInfo.o: StudentInfo.cpp StudentInfo.h
	$(CC) $(FLAGS) -c StudentInfo.cpp -o $@

$(OBJ)/CourseInfo.o: CourseInfo.cpp CourseInfo.h
	$(CC) $(FLAGS) -c CourseInfo.cpp -o $@

tar: clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz

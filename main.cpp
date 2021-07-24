#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void gen_main_file();
void gen_headercpp_file();
void gen_header_file();
void gen_makefile();

string convert_upper(string);

string project_name , class_name ;

int main()
{
	cout << "\nEnter Project name : ";
	getline(cin, project_name);

	cout << "\nEnter Class name : ";
	getline(cin, class_name);

	string folder = "mkdir '"  + project_name + "'";
	system(folder.c_str());
	cout << "\n[+] folder '" << project_name << "' created";

	gen_main_file();
	cout << "\n[+] main.cpp created";
	gen_header_file();
	cout << "\n[+] " << class_name << ".h created";
	gen_headercpp_file();
	cout << "\n[+] " << class_name << ".cpp created";
	gen_makefile();
	cout << "\n[+] makfile created";

	cout << "\n\n[+] Done\n";

	return 0;
}

void gen_makefile()
{
	ofstream file;
	string data , file_name;
	file_name = project_name + "/makefile";
	data = "OBJS = 	main.o ";
	data += class_name + ".o";
	data += "\nmain : $(OBJS)\n\tg++ -o main $(OBJS)";
	data += "\n\n$(OBJS): ";
	data += class_name + ".h";
	data += "\n\nclean :\n	rm -rf *.o main";

	file.open(file_name.c_str());
	file << data;
	file.close();
}

void gen_header_file()
{
	ofstream file;
	string data, documentation, file_name, body;
	file_name = project_name + "/" + class_name + ".h";

	data  = "#ifndef ";
	data += convert_upper(class_name);
	data += "_H\n#define ";
	data += convert_upper(class_name);
	data += "_H\n\n#include <iostream>\n#include <fstream>\n#include <string>\n#include <cstdlib>\n\nusing namespace std;\n\n//-----------------Class--------------------\nclass ";
	data += class_name;
	data += "\n{\n\npublic:\n\t";
	data += class_name;
	data += "();\n\t~";
	data += class_name;
	data += "();\n};\n\n#endif";

	file.open(file_name.c_str());
	file << data;
	file.close();
}

string convert_upper(string s)
{
	string x = s;

	transform(x.begin(), x.end(), x.begin(), ::toupper);

	return x;
}

void gen_headercpp_file()
{
	ofstream file;
	string data, file_name, documentation, body;
	file_name = project_name + "/" + class_name + ".cpp";

	documentation  = "/*\n\t\t\t\tProject Name :	";
	documentation += project_name;
	documentation += "  \n\t\t\t\tDate         :\n\t\t\t\tMade By      :  Vishal Singh\n*/\n\n";

	body += "#include \"";
	body += class_name;
	body += ".h\"\n\n";
	body += class_name + "::" + class_name + "()\n{\n\n}\n\n";
	body += class_name + "::~" + class_name + "()\n{\n\n}";

	data = documentation + body;
	file.open(file_name.c_str());
	file << data;
	file.close();
}

void gen_main_file()
{
	ofstream file;
	string data, documentation, file_name, body;
	file_name = project_name + "/main.cpp";

	documentation  = "/*\n\t\t\t\tProject Name :	";
	documentation += project_name;
	documentation += "  \n\t\t\t\tDate         :\n\t\t\t\tMade By      :  Vishal Singh\n*/\n\n";

	body += "#include \"";
	body += class_name;
	body += ".h\"\n\nusing namespace std;\n\n//-----------------function prototypes------------------\n\n\n//--------------------main function----------------------\nint main()\n{\n\n\n	return 0;\n}\n\n//------------------function definations----------------\n";

	data = documentation + body;
	file.open(file_name.c_str());
	file << data;
	file.close();
}
#include <stdio.h>
#include <stdlib.h>
#include <string>

int revert(std::string& pwd) {
	std::string temp_pwd = pwd;
	int j = 0;
	int i = temp_pwd.length() - 1;
	while (i >= 0) {
		pwd[j] = temp_pwd[i];
		j++;
		i--;
	}

	return 0;
}

int subtracting(std::string& pwd) {
	for (unsigned int i = 0; i < pwd.length(); i++) {
		if ((pwd[i] > '0' && pwd[i] <= '9') || 
			(pwd[i] > 'A' && pwd[i] <= 'Z') || 
			(pwd[i] > 'a' && pwd[i] <= 'z')) {
			pwd[i]--;
		}
	}

	return 0;
}	

int addone(std::string& pwd) {
	for (unsigned int i = 0; i < pwd.length(); i++) {
		if ((pwd[i] >= '0' && pwd[i] < '9') || 
			(pwd[i] >= 'A' && pwd[i] < 'Z') || 
			(pwd[i] >= 'a' && pwd[i] < 'z')) {
			pwd[i]++;
		}
	}

	return 0;
}	

int switch_pos(std::string& pwd) {
	for (unsigned int i = 0; i < pwd.length() - 1;) {
		char t = pwd[i];
		pwd[i] = pwd[i + 1];
		pwd[i + 1] = t;

		i += 2;
	}

	return 0;
}

int enc_pwd(const std::string& input_pwd) {
	std::string pwd = input_pwd;
	//subtracting(pwd);
	switch_pos(pwd);
	revert(pwd);

	printf("%s enc to %s \n", input_pwd.c_str(), pwd.c_str());
	return 0;
}

int dec_pwd(const std::string& input_pwd) {
	std::string pwd = input_pwd;
	revert(pwd);
	switch_pos(pwd);
	//addone(pwd);

	printf("%s dec to %s \n", input_pwd.c_str(), pwd.c_str());
	return 0;
}

int usage() {
	printf("usage : pwdlock option pwd\n");
	printf("	enc : pwdlock -e org_password \n");
	printf("	dec : pwdlock -d enc_password \n");
	return 0;
}

int main(int argc, char** argv) {
	if (argc != 3) {
		return usage();
	}

	std::string type(argv[1]);
	std::string input_pwd(argv[2]);
	if (type == "-e") {
		enc_pwd(input_pwd);
	} else if (type == "-d") {
		dec_pwd(input_pwd);
	} else {
		return usage();
	}

	return 0;
}

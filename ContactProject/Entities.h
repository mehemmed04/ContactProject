#pragma once

struct Human {
	char* name;
	char* phonenumber;
	const char* createdDate;
};


struct Contact {
	Human** humans;
	int count = 0;
};
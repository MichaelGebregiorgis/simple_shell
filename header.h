#ifndef header_h
#define header_h

void hndlExit();
void hndlEnv(char **environ);
void excCmd(const char *cmd);
void snline(char *str);
void chngeDir(const char *dir);
void hndlPwd();

#endif

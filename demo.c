#include <stdio.h>
#include <unistd.h>

void read_file(char*);

void edit_file(char *file_name, int updated_marks);


/*
syscall::read:entry,
syscall::write:entry
/execname=="demo"/
{
	printf("execname:%s uid:%d %s:%s",execname,uid,probefunc,stringof(copyin(arg1,arg2)));
}
*/


int main()
{
        FILE *fp;
        char *command = "whoami";
        char user[255];

        int admin_interface_input;
        int updated_marks;
        
        fp = popen(command, "r");
        fscanf(fp, "%s", user);
        printf("Logged in as : %s\n", user);
        switch (user[0])
        {
                case 'H':
                        // read all files
                        read_file("X.txt");
                        read_file("Y.txt");
                        read_file("Z.txt");
                        break;
                case 'S':
                        // read X.txt
                        read_file("X.txt");
                        break;
                case 'F':
                        // read Y.txt
                        read_file("Y.txt");
                        break;
                case 'A':
                        // read and edit all files
                        while (1)
                        {
                                printf("> Enter 1 to display marks\n> Enter 2 to edit marks\n> Enter 3 to exit: ");
                                scanf("%d", &admin_interface_input);
                                char file_name[6];
                                switch (admin_interface_input)
                                {
                                        case 1:
                                                read_file("X.txt");
                                                read_file("Y.txt");
                                                read_file("Z.txt");
                                                break;
                                        case 2:
                                                printf("> Enter the name of the file to edit: ");
                                                scanf("%s", file_name);
                                                printf("> Enter the value to be updated with: ");
                                                scanf("%d", &updated_marks);
                                                edit_file(file_name, updated_marks);
                                                break;
                                        case 3:
                                                return 0;

                                }
                        }
                        break;

                default:
                        return 0;

        }
        return 0;
}

void read_file(char *file_name)
{
        FILE *file;
        char *contents[10];
        if (access(file_name, F_OK) != 0)
        {
                // the file does not exist
                printf("The file %s does not exist!\n", file_name);
                return;
        }
        if (access(file_name, R_OK) != 0)
        {
                // permission to read denied
                printf("You don't have the permssion to read %s\n", file_name);
                return;
        }
        file = fopen(file_name, "r");
        fscanf(file, "%s", contents);
        printf("%c: %s\n", file_name[0], contents);
        fclose(file);
}

void edit_file(char *file_name, int updated_marks)
{
        if (access(file_name, F_OK) != 0)
        {
                // the file does not exist
                printf("The file %s does not exist!", file_name);
                return;
        }
        if (access(file_name, W_OK) != 0)
        {
                // permission to write denied
                printf("You don't have the permssion to read %s", file_name);
                return;
        }

        FILE *fp = fopen(file_name, "w");
        fprintf(fp, "%d", updated_marks);
        fclose(fp);
        printf("\n> Update successful\n");

}


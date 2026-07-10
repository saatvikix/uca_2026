#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;

	if (argc < 2)
	{
		printf("No arguments provided");
		return 1;
	}

	// ---------------- ADD ----------------

	if (strcmp(argv[1], "--add") == 0)
	{
		if (argc < 3)
		{
			printf("Nothing to log.\n");
			return 1;
		}

		fd = open("audit.log", O_WRONLY | O_APPEND | O_CREAT, 0644);

		if (fd == -1)
		{
			printf("Unable to open file.\n");
			return 1;
		}

		write(fd, argv[2], strlen(argv[2]));
		write(fd, "\n", 1);

		close(fd);

		printf("Log written successfully.\n");
	}

	// ---------------- VIEW ----------------

	else if (strcmp(argv[1], "--view") == 0)
	{
		char buffer[100];
		int bytesRead;

		fd = open("audit.log", O_RDONLY);

		if (fd == -1)
		{
			printf("Unable to open file.\n");
			return 1;
		}

		while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
		{
			write(STDOUT_FILENO, buffer, bytesRead);
		}

		close(fd);
	}

	else
	{
		printf("Unknown command.\n");
	}

	return 0;
}
	// if (is_here_doc(argv[1]) == 0)
	// {
	// 	file_exists_check(argv);
	// 	file_is_readable_check(argv);
	// }
	// check_cmds(argc, argv, env);

// void	check_cmds(int argc, char **argv, char **env);
// void	file_is_readable_check(char **argv);
// void	file_exists_check(char **argv);

// void	file_exists_check(char **argv)
// {
// 	char	*error_msg;
// 	char	*cmd;
// 	char	*file_name;

// 	file_name = argv[1];
// 	if (access(file_name, F_OK) == -1)
// 	{
// 		cmd = get_cmd_without_flags(argv[2]);
// 		error_msg = ft_strjoin_free_1(cmd, ": ");
// 		error_msg = ft_strjoin_free_1(error_msg, file_name);
// 		error_msg = ft_strjoin_free_1(error_msg, ": no such file or directory1\n");
// 		perror(error_msg);
// 		free(error_msg);
// 	}
// }

// void	file_is_readable_check(char **argv)
// {
// 	char	*error_msg;
// 	char	*cmd;
// 	char	*file_name;

// 	file_name = argv[1];
// 	if (access(file_name, R_OK) == -1)
// 	{
// 		cmd = get_cmd_without_flags(argv[2]);
// 		error_msg = ft_strjoin_free_1(cmd, ": ");
// 		error_msg = ft_strjoin_free_1(error_msg, file_name);
// 		error_msg = ft_strjoin_free_1(error_msg, ": Permission denied1\n");
// 		perror(error_msg);
// 		free(error_msg);
// 	}
// }

// void	check_cmds(int argc, char **argv, char **env)
// {
// 	int		index;
// 	char	*cmd_path;
// 	char	*cmd;
// 	char	*error_msg;

// 	if (is_here_doc(argv[1]))
// 		index = 3;
// 	else
// 		index = 2;
// 	while (index < argc - 1)
// 	{
// 		cmd = get_cmd_without_flags(argv[index]);
// 		cmd_path = get_cmd_path(get_path(env), cmd);
// 		if (is_full_path(cmd) == 0 || cmd_path == NULL)
// 		{
// 			error_msg = ft_strjoin("command not found: ", argv[index]);
// 			error_msg = ft_strjoin_free_1(error_msg, "\n");
// 			perror(error_msg);
// 			free(error_msg);
// 		}
// 		free(cmd);
// 		free(cmd_path);
// 		index++;
// 	}
// }

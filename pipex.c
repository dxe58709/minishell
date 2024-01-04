#include ""

/*
 ./pipex file1 cmd1 cmd2 file2
 < file1 cmd1 | cmd2 > file2

  ./pipex infile "ls -l" "wc -l" outfile
  < infile ls -l | wc -l > outfile

   ./pipex infile "grep a1" "wc -w" outfile
   < infile grep a1 | wc -w > outfile
 */

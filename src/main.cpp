#include "IO/OutputStream.hpp"

int main(int, const char*[])
{
   IO::OutputStream out(STDOUT_FILENO);
   out.Write("Hello World!\n");
   return 0;
}

#include <iostream>

int main(int argc, char *argv[])
{
   std::cout << "Hello mate!" << std::endl;

   if (argc == 1) {
       std::cout << "No extra arguments used" << std::endl;
   } else if (argc >= 2) {
       std::cout << "Used " << argc << " arguments" << std::endl;
       std::cout << "What was passed:" << std::endl;
       for (uint32_t counter = 0; counter < argc; counter++)
           printf("\nargv[%d]: %s", counter, argv[counter]);
   }

   return 0;
}
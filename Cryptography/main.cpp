#include <iostream>
#include <array>

#include <cstdio>
#include <openssl/ssl.h>
#include <openssl/bio.h>

constexpr int MAX_BUFFER_SIZE{ 512 };

int main(int argc, char* argv[])
{
   BIO* bio_out	= nullptr;
   BIO* bio_in	= nullptr;
   int inByte, outByte;
   std::array<char, MAX_BUFFER_SIZE> buffer;
//   char buffer[MAX_BUFFER_SIZE];
//   memset(buffer, 0, MAX_BUFFER_SIZE);
   buffer.fill('\0');

   if(argc != 3){
      std::cout << "Usage: bio_file <file-read> <file-write>" << std::endl;
      return 1;
   }

   bio_in = BIO_new_file(argv[1], "r");
   bio_out = BIO_new_file(argv[2], "w");
   while((inByte = BIO_read(bio_in, buffer.data(), MAX_BUFFER_SIZE)) > 0)
   {
      outByte = BIO_write(bio_out, buffer.data(), inByte);

      if(inByte != outByte){
         std::cout << "In Bytes: " << inByte << " out Bytes: "
                   << outByte << '\n';
         break;
      }
   }

   BIO_free(bio_in);
   BIO_free(bio_out);
   
   return 0;
}

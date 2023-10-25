#include <iostream>
#include <array>

#include <cstdio>

#include <openssl/ssl.h>
#include <openssl/bio.h>

// Makes expression be const at compile-time
// Along with only being static to this file.
constexpr int MAX_BUFFER_SIZE{ 512 };

/*
 * BIO_f_base64 
 * BIO_f_base64() is a filter BIO that returns base64 BIO method
 *
 *	1) encodes any data written through it
 *	2) decodes any data read through it
 *
 */

int main(int argc, char* argv[])
{
   BIO* bio_out	= nullptr;
   BIO* bio_in	= nullptr;
   BIO* bio_b64	= nullptr;
   int inByte, outByte;
   std::array<char, MAX_BUFFER_SIZE> buffer;
//   char buffer[MAX_BUFFER_SIZE];
//   memset(buffer, 0, MAX_BUFFER_SIZE);
   buffer.fill('\0');

   if(argc != 3){
      std::cout << "Usage: bio_b64_decoded <encoded file> <source file>" << std::endl;
      return 1;
   }

   bio_in = BIO_new_file(argv[1], "rb");
   bio_out = BIO_new_file(argv[2], "w");

   bio_b64 = BIO_new(BIO_f_base64());
   BIO_push(bio_b64, bio_in);
   
   while((inByte = BIO_read(bio_b64, buffer.data(), MAX_BUFFER_SIZE)) > 0)
   {
      outByte = BIO_write(bio_out, buffer.data(), inByte);

      if(inByte != outByte){
         std::cout << "In Bytes: " << inByte << " out Bytes: "
                   << outByte << '\n';
         break;
      }
   }

   BIO_flush(bio_b64);

//   BIO_free(bio_in);
   BIO_free(bio_out);
   BIO_free_all(bio_b64);
   return 0;
}

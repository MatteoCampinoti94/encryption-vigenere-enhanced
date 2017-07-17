# encryption-vigenere-enhanced
C++ program to encrypt/decrypt files byte per byte using an enhanced version of the [Vigénere cypher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)

## How it works
The program asks for a file and a key.
As the file is a read a position counter increases and it is used to get the int value of the corresponding key letter and to modify the current byte of the file.

While the original Vigénere cypher used only alphabetical positions this program uses the int value of the character and the wrapping property of chars in C/C++. Because of this once the encryption has finished the resulting file is not readable since all the bytes have been scrambled. Moreso, since it doesn't use the alphabet any type of file can be encrypted.

Decryption is as easy as running the program in the opposite direction. Whereas in encrypt mode the value of the key is added, in decrypt mode the value is subtracted. The cypher function uses a simple int value passed by the parent function to differentiate the two modes. This values can be changed to any int as long as they are opposite, otherwise once the file has been encrypted it would be really difficult to decrypt it though not impossible. Theoretically with the right values it would be possible to encrypt a file so that a user would need multiple keys and passages to decrypt it.

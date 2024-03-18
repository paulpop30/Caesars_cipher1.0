# Caesars_cipher1.0
This project is used to decript the caesars cipher in a text
Caesar Cipher Breaker using Frequency Analysis


Overview:
This program implements a Caesar cipher breaker using frequency analysis. The Caesar cipher is a substitution cipher where each letter in the plaintext is shifted a certain number of places down or up the alphabet. Frequency analysis is a technique used to decrypt a message encrypted with a substitution cipher by analyzing the frequency of letters in the ciphertext.

How it Works:

--Read Distribution: The program reads a distribution of letters from a file called distribution.txt. This distribution represents the expected frequency of each letter in the English language.

--Compute Histogram: The program computes the frequency distribution of letters in the encrypted text.

--Compute Chi-squared Distance: It calculates the Chi-squared distance between the frequency distribution of the encrypted text and the expected distribution of letters in English.

--Break Caesar's Cipher: The program iterates through all possible shifts (0 to 25) and decrypts the text using each shift. It computes the Chi-squared distance for each decrypted text and selects the shift that minimizes the distance.

--Print Decrypted Message: Finally, the program prints the decrypted message using the best shift found.

Input:
The program reads the encrypted message from the encryptedText variable in the main function.
Output:
The program prints the decrypted message obtained after breaking Caesar's cipher using frequency analysis.
Files:
caesar_cipher_breaker.c: Source code for the Caesar cipher breaker.
distribution.txt: File containing the distribution of letters in the English language.
Dependencies:
Standard C libraries: stdio.h, stdlib.h, string.h, float.h.
Notes:
The program assumes the input text is encrypted using a Caesar cipher.
Ensure the distribution.txt file is present and correctly formatted before running the program.

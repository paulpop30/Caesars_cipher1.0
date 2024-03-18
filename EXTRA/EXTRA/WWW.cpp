#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

// Function to read the distribution of letters from a file
void readDistribution(float* distribution) {
    FILE* file;
    errno_t err = fopen_s(&file, "distribution.txt", "r");
    if (err != 0 || file == NULL) {
        printf("Error: Unable to open the distribution file.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < 26; i++) {
        fscanf_s(file, "%f", &distribution[i]);
    }

    fclose(file);
}

// Function to compute the normalized frequency of each character in a text
void computeHistogram(char* text, float* histogram) {
    int i;
    int total = 0;
    for (i = 0; i < 26; i++) {
        histogram[i] = 0.0;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            histogram[text[i] - 'a']++;
            total++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            histogram[text[i] - 'A']++;
            total++;
        }
    }

    for (i = 0; i < 26; i++) {
        histogram[i] /= total;
    }
}

// Function to compute the Chi-square distance between two histograms
float computeChiSquared(float* histogram1, float* histogram2) {
    float chiSquared = 0.0;
    int i;
    for (i = 0; i < 26; i++) {
        chiSquared += ((histogram1[i] - histogram2[i]) * (histogram1[i] - histogram2[i])) / histogram2[i];
    }
    return chiSquared;
}

// Function to break Caesar's cipher using frequency analysis
void breakCaesarCipher(char* encryptedText, float* distribution) {
    float minChiSquared = FLT_MAX;
    int bestShift = 0;

    int length = strlen(encryptedText);
    char* decryptedText = (char*)malloc((length + 1) * sizeof(char)); // Dynamically allocate memory

    float histogram[26];

    for (int shift = 0; shift < 26; shift++) {
        for (int i = 0; encryptedText[i] != '\0'; i++) {
            if (encryptedText[i] >= 'a' && encryptedText[i] <= 'z') {
                decryptedText[i] = 'a' + (encryptedText[i] - 'a' - shift + 26) % 26;
            }
            else if (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z') {
                decryptedText[i] = 'A' + (encryptedText[i] - 'A' - shift + 26) % 26;
            }
            else {
                decryptedText[i] = encryptedText[i]; // Preserve spaces and punctuation marks
            }
        }
        decryptedText[length] = '\0';

        computeHistogram(decryptedText, histogram);
        float chiSquared = computeChiSquared(histogram, distribution);

        if (chiSquared < minChiSquared) {
            minChiSquared = chiSquared;
            bestShift = shift;
        }
    }

    printf("The decrypted message with Caesar's cipher is:\n");
    for (int i = 0; encryptedText[i] != '\0'; i++) {
        if (encryptedText[i] >= 'a' && encryptedText[i] <= 'z') {
            printf("%c", 'a' + (encryptedText[i] - 'a' - bestShift + 26) % 26);
        }
        else if (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z') {
            printf("%c", 'A' + (encryptedText[i] - 'A' - bestShift + 26) % 26);
        }
        else {
            printf("%c", encryptedText[i]); // Preserve spaces and punctuation marks
        }
    }
    printf("\n");

    free(decryptedText); // Free dynamically allocated memory
}

int main() {
    // Read the distribution of letters from the file
    float distribution[26];
    readDistribution(distribution);

    // Encrypted message
    char encryptedText[] = "Uf ime ftq nqef ar fuyqe, uf ime ftq iadef ar fuyqe, uf ime ftq msq ar iuepay, uf ime ftq msq ar raaxuetzqee, uf ime ftq qbaot ar nqxuqr, uf ime ftq qbaot ar uzodqpgxufk, uf ime ftq eqmeaz ar xustf, uf ime ftq eqmeaz ar pmdwzqee, uf ime ftq ebduzs ar tabq, uf ime ftq iuzfqd ar pqebmud.";

    // Break Caesar's cipher using frequency analysis
    breakCaesarCipher(encryptedText, distribution);

    return 0;
}

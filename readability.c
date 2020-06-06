#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    // Initialise counts for letters, words and sentences
    float letters = 0, words = 1, sentences = 0;

    // Calculate string length
    int length = strlen(text);

    // Loop through each element in string
    for (int i = 0; i < length; i++)
    {
        // Check if character is alphabetic
        if (isalpha(text[i]))
        {
            // Add one to letter count
            letters++;
        }

        // Check if character is a space
        if (isspace(text[i]))
        {
            // Add one to word count
            words++;
        }

        // Check if the end of a sentence
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            // Add one to sentence count
            sentences++;
        }
    }

    // Calculate index
    int index = round(0.0588 * (letters / words) * 100 - 0.296 * (sentences / words) * 100 - 15.8);

    // Print Grade level to user
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
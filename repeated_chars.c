//  Copyright © 2019 Milan Patel. All rights reserved.
//
//  This program takes in a string and finds characters that are repeated three times and changes the string.
//  The number 3 are added to the character string.

#include <stdio.h>

void replace(char *str, char *replaced)         //replace function for string
{

    int i = 0;
    int j = 0;
    int counter = 0;            //Counter
    int endingChar = '\0';      //Ending Char
    
    while(str[i] != '\0')               //go while end of line not reached
    {
        if(endingChar == str[i])
        {
            counter++;
        }
        else
        {
            if(counter < 3)                         //taking account for non 3 repeaters
            {
                int k;
                for(k=0; k<counter; k++)
                {
                    replaced[j++] = endingChar;
                }
            }
            else
            {
                replaced[j++] = endingChar;
                replaced[j++] = '3';                        //insert 3 after 3 repeating characters found
            }
            endingChar = str[i];
            counter = 1;                                    //reset counter
        }
        i++;
    }
    
    if(counter != 0)
    {
        if(counter < 3)
        {
            int k;
            for(k=0; k<counter; k++)
            {
                replaced[j++] = endingChar;
            }
        }
        else
        {
            replaced[j++] = endingChar;
            replaced[j++] = '3';                    //insert 3
        }
    }
    replaced[j] = '\0';
}

//*******************************************************************************

int read_line(char *str, int n)     //reading in line with ptr arith
{
    
    int ch;                         //Declare variables
    int i = 0;
    
    while((ch = getchar()) != '\n')      //input while not end of line
    {
        if(i < n)
        {
            *str++ = ch;                    //pointer input
            i++;
        }
    }
    
    *str = '\0';    // End string
    return i;       // Number of characters stored
}

//************************************************************************************

int main(void)
{
    char str[1000];                              //Declare input variable with appropriate length
    char replaced[1000];                          //Declare output variable with appropriate length
  
    printf("Please enter string input: ");                //Prompt user for string input
    read_line(str, 1000);                         //read_line command for str
    
    replace(str, replaced);                      //Call replace function
    
    printf("\nEncoded:\n%s\n", replaced);         //Print output with replaced string
    
    return 0;
}

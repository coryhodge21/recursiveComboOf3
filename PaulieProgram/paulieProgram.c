/**
 * /file paulieProgram.c
 * 
 * Author: Cory W. Hodge
 * Date:   October 9th, 2020
 * 
 * This Program opens a file "./list.txt" in the current directory
 * Parsing the file, expects to find a text list of 32 team names. 
 * It then produces an acsending list of every combination 
 * that can be made from 32 options, in groups of three
 * 
 * Not for distribution
 */

#include "stdio.h"
#include "string.h" // for strlen()

    // Create file pointers
    FILE * input_file_Ptr;
    FILE * outPtr_file_Ptr;

    // buffer
    const int BUFF_SIZE = 50;
    char BUFFER[BUFF_SIZE];

    // Input String Array
    //const int LIST_ARRAY_LENGTH = 32;
    //////////////////////////////////////
    // DEBUGGING
    const int LIST_ARRAY_LENGTH = 6;
    const int LIST_ARRAY_STRING_LENGTH = 15;
    char listArr[LIST_ARRAY_LENGTH][LIST_ARRAY_STRING_LENGTH] = {0};


// /// \brief Print State to File
// void printStateToFile(FILE* filePtr, char list[][LIST_ARRAY_STRING_LENGTH], int slow, int med, int fast);
// ///////////////////////////////////
// //  DEBUG
// //////////////////////////////////
// // \brief Print State to Terminal
// void printStateToTerminal(char * list[][LIST_ARRAY_STRING_LENGTH], int slow, int med, int fast);

int main() 
{

    // Parsing Pointers
    int slowIndex, medIndex, fastIndex;

    // open file to parse
    //input_file_Ptr = fopen("./team_list.txt", "r");
    //////////////////////////////////////
    // DEBUGGING
    input_file_Ptr = fopen("./test.txt", "r");

    // open file to write single occurance list
    // truncate file if it already exists
    outPtr_file_Ptr = fopen("./single_occurance_list.txt", "w+");

    // Parse file and store strings to array
    for(int i = 0; i < LIST_ARRAY_LENGTH ; i++ ) {

        // Read Line from file
        fgets(listArr[i], BUFF_SIZE, input_file_Ptr);

        // replace new line symbol with space
        listArr[i][strlen(listArr[i]) - 1] = ' ';
    }

    /** ************************************************************************** **/
    /**
     *  SINGLE OCCURANCE LIST
     *  In Ascending order, create groups of three teams
     *     each team combination should only exist once.
     */
    // Teams Display at top of page
    fprintf(outPtr_file_Ptr, "TEAMS: \n");

    for( int i = 0 ; i < LIST_ARRAY_LENGTH ; i++) {
        // List Recived Teams from external file
        fprintf(outPtr_file_Ptr, "%s", listArr[i]);
    }

    // Combination Head
    for( slowIndex = 0; ( slowIndex ) < ( LIST_ARRAY_LENGTH - 2 ) ; slowIndex++ ) {

        // Group
        fprintf(outPtr_file_Ptr, "\n \n Group %s \n \n", listArr[slowIndex]);


        for( medIndex = (slowIndex + 1) ; ( medIndex ) < ( LIST_ARRAY_LENGTH - 1 ) ; medIndex++ ){


            for( fastIndex = (medIndex + 1) ; fastIndex < ( LIST_ARRAY_LENGTH ) ; fastIndex++ ) {

                // Slow paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[slowIndex]);

                // hyphen
                fprintf(outPtr_file_Ptr, "- ");

                // Med paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[medIndex]);

                // hyphen
                fprintf(outPtr_file_Ptr, "- ");

                // fast paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[fastIndex]);

                // New Line for next team group
                fprintf(outPtr_file_Ptr, "\n");


            }
        }
    }

    // close single occurance list
    fclose(outPtr_file_Ptr);

    /** ****************************************************** **/
    /**
     *  MULTI OCCURANCE LIST
     *  In Ascending order, create groups of three teams
     *     each team combination be represented.
     */

    // open file to write multi occurance list
    // truncate file if it already exists
    outPtr_file_Ptr = fopen("./multi_occurance_list.txt", "w+");

    // Teams Display at top of page
    fprintf(outPtr_file_Ptr, "TEAMS: \n");

    for( int i = 0 ; i < LIST_ARRAY_LENGTH ; i++) {
        // List Recived Teams from external file
        fprintf(outPtr_file_Ptr, "%s", listArr[i]);
    }

    // SLOW: Start Combination Head
    for( slowIndex = 0; ( slowIndex ) < ( LIST_ARRAY_LENGTH - 2 ) ; slowIndex++ ) {

        // Group
        fprintf(outPtr_file_Ptr, "\n \n Group %s \n \n", listArr[slowIndex]);

        // MED : forward
        for( medIndex = (slowIndex + 1) ; medIndex < ( LIST_ARRAY_LENGTH - 1 ) ; medIndex++ ){
            
            // FAST : display forward index
            for( fastIndex = (medIndex + 1) ; fastIndex < ( LIST_ARRAY_LENGTH ) ; fastIndex++ ) {

                    // Print To File
                    //printStateToFile(outPtr_file_Ptr, listArr[slowIndex][LIST_ARRAY_STRING_LENGTH], slowIndex, medIndex, fastIndex);

                    // DEBUG: Print To Terminal
                    //printStateToTerminal(listArr[slowIndex][LIST_ARRAY_STRING_LENGTH], slowIndex, medIndex, fastIndex);
            
                // Slow paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[slowIndex]);

                // hyphen
                fprintf(outPtr_file_Ptr, "- ");

                // Med paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[medIndex]);

                // hyphen
                fprintf(outPtr_file_Ptr, "- ");

                // fast paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[fastIndex]);

                // New Line for next team group
                fprintf(outPtr_file_Ptr, "\n");



                printf("%s", listArr[slowIndex]);

                // hyphen
                printf("- ");

                // Med paced incrementing team name
                printf("%s", listArr[medIndex]);

                // hyphen
                printf("- ");

                // fast paced incrementing team name
                printf("%s", listArr[fastIndex]);

                // New Line for next team group
                printf("\n");
            }

            // FAST: recover past index's
            for( fastIndex = 0 ; fastIndex < medIndex ; fastIndex++) {

                // skip slowindex already printed
                if(fastIndex != slowIndex) {
    
                                    // Slow paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[slowIndex]);
                // hyphen
                fprintf(outPtr_file_Ptr, "- ");
                // Med paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[medIndex]);
                // hyphen
                fprintf(outPtr_file_Ptr, "- ");
                // fast paced incrementing team name
                fprintf(outPtr_file_Ptr, "%s", listArr[fastIndex]);
                // New Line for next team group
                fprintf(outPtr_file_Ptr, "\n");



                printf("%s", listArr[slowIndex]);
                // hyphen
                printf("- ");
                // Med paced incrementing team name
                printf("%s", listArr[medIndex]);
                // hyphen
                printf("- ");
                // fast paced incrementing team name
                printf("%s", listArr[fastIndex]);
                // New Line for next team group
                printf("\n");

                }// End IF
            
            }// End Fast Recover

        }// End Med Forward

        // MED: Recover
        // for( medIndex = 0 ; medIndex < (slowIndex - 1 ) ; medIndex++) {

        //     // recover past index's
        //     for( fastIndex = (medIndex + 1) ; fastIndex < LIST_ARRAY_LENGTH ; fastIndex++) {

        //         // skip slowindex already printed
        //         if(fastIndex != slowIndex) {
        //             // Print To File
        //             //rintStateToFile(outPtr_file_Ptr, listArr, slowIndex, medIndex, fastIndex);

        //             // DEBUG: Print To Terminal
        //             //printStateToTerminal(listArr, slowIndex, medIndex, fastIndex);



        //         }// End IF
            
        //     }// End Fast Index

        // }// End Med Rocover

    }// End Slow

    // close files and exit
    fclose(input_file_Ptr);
    fclose(outPtr_file_Ptr);
    return 0;
}

// /// \brief Print State to File
// void printStateToFile(FILE* filePtr, char list[][LIST_ARRAY_STRING_LENGTH], int slow, int med, int fast) {
    
//     // Slow paced incrementing team name
//     fprintf(filePtr, "%s", list[slow][LIST_ARRAY_STRING_LENGTH]);
    
//     // hyphen
//     fprintf(filePtr, "- ");
    
//     // Med paced incrementing team name
//     fprintf(filePtr, "%s", list[med][LIST_ARRAY_STRING_LENGTH]);
    
//     // hyphen
//     fprintf(filePtr, "- ");
    
//     // fast paced incrementing team name
//     fprintf(filePtr, "%s", list[fast][LIST_ARRAY_STRING_LENGTH]);
    
//     // New Line for next team group
//     fprintf(filePtr, "\n");
// };


// ///////////////////////////////////
// //  DEBUG
// //////////////////////////////////
// // \brief Print State to Terminal
// void printStateToTerminal(char * list[][LIST_ARRAY_STRING_LENGTH], int slow, int med, int fast) {

//     printf("Group %d \n \n", slow);
              
//     // Slow paced incrementing team name
//     printf("%s", list[slow][LIST_ARRAY_STRING_LENGTH]);

//     // hyphen
//     printf("- ");

//     // Med paced incrementing team name
//     printf("%s", list[med][LIST_ARRAY_STRING_LENGTH]);

//     // hyphen
//     printf("- ");

//     // fast paced incrementing team name
//     printf("%s", list[fast][LIST_ARRAY_STRING_LENGTH]);

//     // New Line for next team group
//     printf("\n");
// };
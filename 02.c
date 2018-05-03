// Calculation of Scores
// Mechanical Engineering, Junior Student, PME 19
// Student ID : 104033250
// Name : 吳杰儒

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WEIGHT_ASSIGNMENT 0.3
#define WEIGHT_MIDTERM 0.3
#define WEIGHT_FINAL 0.4
#define NUM_STUDENT 3

// function declarations
void input_data(float scoreTable[][5], int nrow, int ncol);
void calculator(float scoreTable[][5], int nrow, int ncol);
void show_table(float scoreTable[][5], int nrow, int ncol);
void calculateAvgScore(float scoreTable[][5], int nrow, int ncol);
void calculateSD(float scoreTable[][5], int nrow, int ncol);

float calculateRawScore(float assignment, float midterm, float final);
float calculateAdjScore(float rawScore);


int main()
{
    float scoreTable[NUM_STUDENT+2][5] = {0, 0};    // 2-D array, Default them to 0
    input_data(scoreTable, NUM_STUDENT+2, 5);
    calculator(scoreTable, NUM_STUDENT+2, 5);
    show_table(scoreTable, NUM_STUDENT+2, 5);
}


// Enter the scores of 3 students
void input_data(float scoreTable[][5], int nrow, int ncol)
{
    int i = 0;
    do
    {   printf("Input scores of Assignment, Midterm & Final for student number %d\n", i+1);
        scanf("%f %f %f", &scoreTable[i][0], &scoreTable[i][1], &scoreTable[i][2]);
        i++;
    } while(i < 3);
}

// calculate all the scores
void calculator(float scoreTable[][5], int nrow, int ncol)
{
    int i;
    for(i = 0; i < NUM_STUDENT; i++)
    {
        scoreTable[i][3] = calculateRawScore(scoreTable[i][0], scoreTable[i][1], scoreTable[i][2]);
        scoreTable[i][4] = calculateAdjScore(scoreTable[i][3]);
    }
    calculateAvgScore(scoreTable, 5, 5);
    calculateSD(scoreTable, 5, 5);

}

// raw score
float calculateRawScore(float assignment, float midterm, float final)
{
    float rawScore;
    rawScore = (assignment * WEIGHT_ASSIGNMENT) + (midterm * WEIGHT_MIDTERM) + (final * WEIGHT_FINAL);
    return rawScore;
}

// adjusted score
float calculateAdjScore(float rawScore)
{
    float adjScore;
    adjScore = (pow(rawScore, 0.4) * 12) + 25;
    return adjScore;
}

// average score
void calculateAvgScore(float scoreTable[][5], int nrow, int ncol)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        scoreTable[3][i] = ((scoreTable[0][i] + scoreTable[1][i] + scoreTable[2][i]) / NUM_STUDENT);
    }
}

// standard deviation
void calculateSD(float scoreTable[][5], int nrow, int ncol)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        float x, y, z, a;
        x = scoreTable[0][i] - scoreTable[3][i];
        y = scoreTable[1][i] - scoreTable[3][i];
        z = scoreTable[2][i] - scoreTable[3][i];
        a = ((pow(x, 2) + pow(y, 2) + pow(z, 2)) / NUM_STUDENT);
        scoreTable[4][i] = pow(a, 0.5);
    }
}

// print out the final table
void show_table(float scoreTable[][5], int nrow, int ncol)
{
    int i, j;
    int width[] = {14, 15, 13, 12, 17};     // number of space between each header
    int length = strlen("Num   Assignments   Midterm Exam   Final Exam   Raw Score   Adjusted Score");

    // print out dashes
    for(i = 0; i < length; i++)
    {
        printf("-");
    }

    // print out the header
    printf("\nNum   Assignments   Midterm Exam   Final Exam   Raw Score   Adjusted Score\n");

    // print out dashes
    for(i = 0; i < length; i++)
    {
        printf("-");
    }
    printf("\n");

    // print out the first 3 rows
    for(i = 0; i < NUM_STUDENT; i++)
    {
        printf("%-3d", i+1);
        for(j = 0; j < 5; j++)
        {
            if(j < 3)       // Assignment, Midterm, Final
            {
                printf("%*.0f", width[j], scoreTable[i][j]);
            }
            else            // Raw Score, Adjusted Score
            {
                printf("%*.1f", width[j], scoreTable[i][j]);
            }
        }
        printf("\n");
    }

    // print out dashes
    for(i = 0; i < length; i++)
    {
        printf("-");
    }

    // print out Average Scores
    printf("\nAvg");
    for(j = 0; j < 5; j++)
    {
        printf("%*.1f", width[j], scoreTable[3][j]);
    }

    // print out Standard Deviation
    printf("\nSD ");
    for(j = 0; j < 5; j++)
    {
        printf("%*.1f", width[j], scoreTable[4][j]);
    }
    printf("\n");
}

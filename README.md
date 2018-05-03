# Score-Counter

Write a program that calculates the raw scores, tuned scores and their statistics (average and standard deviation).
1. Input: Scores of assignments, midterm exam, and final exam for n students
2. Calculation: Write functions for calculation:
(a) calculateRawScore:
rawScore = assignment × 30% + midterm × 30% + final × 40%
(b) calculateAdjScore:
(c) calculateAvg and calculateSD: Calculate the average and standard deviation of the above
 scores over n students.
adjScore = 􏰁5 rawScore2 × 12 + 25
Avg
= n
1 􏰀n
xi
􏰂(xi −Avg)2
 SD 3. Output: Use a table to summarize the input
= n
scores and calculation results.
Num Assignments
1 80 2 40 3 35
Avg 51.7 SD 20.1
Midterm Exam
70 50 30
50.0 16.3
Final Exam
75 45 25
48.3 20.5
Raw Score
     75.0
     45.0
     29.5
49.8 18.9
Adjusted Score
          92.5
          80.0
          71.5
81.3 8.6
i=1
      4. Hint: #define the constants in preprocessor directives: number of student (n = 3) and weights (30%, 30%, and 40% for assignments, midterm exam, and final exam, respectively)

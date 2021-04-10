#include <stdbool.h>
#include <stdio.h>

typedef struct {
  float generalTest;
  float logicTest;
  float skillTestA;
  float skillTestB;
  float skillTestC;
} TestResults;

float totalGrade(const TestResults testResults) {
  return testResults.generalTest + testResults.logicTest +
         testResults.skillTestA + testResults.skillTestB +
         testResults.skillTestC;
}

float totalSkillTestGrade(const TestResults testResults) {
  return testResults.skillTestA + testResults.skillTestB +
         testResults.skillTestC;
}

bool nPerfectScores(const TestResults testResults, const int numGrades) {
  int numPerfectScores = 0;
  if (testResults.generalTest == 100) {
    numPerfectScores++;
  }
  if (testResults.logicTest == 100) {
    numPerfectScores++;
  }
  if (testResults.skillTestA == 100) {
    numPerfectScores++;
  }
  if (testResults.skillTestB == 100) {
    numPerfectScores++;
  }
  if (testResults.skillTestC == 100) {
    numPerfectScores++;
  }

  return numPerfectScores >= numGrades;
}

bool nAboveThresholdScores(const TestResults testResults,
                           const float gradeThreshold,
                           const int numGrades) {
  int numAboveThresholdScores = 0;

  if (testResults.generalTest > gradeThreshold) {
    numAboveThresholdScores++;
  }
  if (testResults.logicTest > gradeThreshold) {
    numAboveThresholdScores++;
  }
  if (testResults.skillTestA > gradeThreshold) {
    numAboveThresholdScores++;
  }
  if (testResults.skillTestB > gradeThreshold) {
    numAboveThresholdScores++;
  }
  if (testResults.skillTestC > gradeThreshold) {
    numAboveThresholdScores++;
  }

  return numAboveThresholdScores >= numGrades;
}

bool isHired(const TestResults testResults) {
  return totalGrade(testResults) > 450 ||
         totalSkillTestGrade(testResults) > 270 ||
         nPerfectScores(testResults, 4) ||
         nAboveThresholdScores(testResults, 90, 5);
}

bool isForInterview(const TestResults testResults) {
  return (totalSkillTestGrade(testResults) > 250 &&
          nAboveThresholdScores(testResults, 80, 5)) ||
         nPerfectScores(testResults, 3) ||
         nAboveThresholdScores(testResults, 90, 4);
}

bool isForEvaluation(const TestResults testResults) {
  return nAboveThresholdScores(testResults, 70, 5) ||
         nPerfectScores(testResults, 2) ||
         nAboveThresholdScores(testResults, 90, 2);
}

TestResults getTestResults(void) {
  TestResults testResults;

  printf("Enter grade for General Test: ");
  scanf(" %f", &testResults.generalTest);
  printf("Enter grade for Logic Test: ");
  scanf(" %f", &testResults.logicTest);
  printf("Enter grade for Skill Test A: ");
  scanf(" %f", &testResults.skillTestA);
  printf("Enter grade for Skill Test B: ");
  scanf(" %f", &testResults.skillTestB);
  printf("Enter grade for Skill Test C: ");
  scanf(" %f", &testResults.skillTestC);

  return testResults;
}

int main() {
  TestResults testResults = getTestResults();
  if (isHired(testResults)) {
    puts("You are hired!");
  } else if (isForInterview(testResults)) {
    puts("You are for interview.");
  } else if (isForEvaluation(testResults)) {
    puts("You are for evaluation.");
  } else {
    puts("You are rejected.");
  }
  return 0;
}
